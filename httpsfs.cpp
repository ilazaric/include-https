#include <string>
#include <filesystem>
#include <fstream>
// #include <iostream>
#include <cassert>

#include "errno.h"

#define FUSE_USE_VERSION 35
#include <fuse3/fuse.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

namespace ivl::httpsfs {

  std::string prefix;

  void load_to_cache(const char* path) try {
    auto cachepath = prefix + path;
    if (std::filesystem::exists(cachepath))
      return;
    if (std::filesystem::path(cachepath).extension().empty()){
      std::filesystem::create_directory(cachepath);
      return;
    }
        
    cURLpp::Easy handle;
    handle.setOpt(cURLpp::Options::Url(std::string("https:/") + path));
    std::ofstream os(cachepath);
    cURLpp::options::WriteStream ws(&os);
    handle.setOpt(ws);
    // handle.setOpt(cURLpp::Options::Verbose(true));
    handle.perform();
    os.close();

    if (cURLpp::infos::ResponseCode::get(handle) != 200){
      std::filesystem::remove(cachepath);
      std::filesystem::create_directory(cachepath);
    }
  } catch(...){
    auto cachepath = prefix + path;
    if (std::filesystem::exists(cachepath)){
      std::filesystem::remove(cachepath);
      std::filesystem::create_directory(cachepath);
    }
  }

  int getattr(const char *path, struct stat *st, struct fuse_file_info *fi){
    load_to_cache(path);
    auto realpath = prefix + path;
    auto retvalue = ::stat(realpath.c_str(), st);
    return retvalue;
  }

  int read(const char *path, char *buff, size_t size, off_t offset,
           struct fuse_file_info *){
    auto realpath = prefix + path;
    std::ifstream is(realpath);
    is.seekg(offset);
    is.read(buff, size);
    return size;
  }

  static fuse_operations ops = {
    .getattr = getattr,
    .read = read,
  };
  
} // namespace ivl::httpsfs

int main(int argc, char* argv[]){
  ivl::httpsfs::prefix = std::filesystem::canonical(argv[0]).parent_path() / "cache";
  assert(std::filesystem::is_directory(ivl::httpsfs::prefix));

  cURLpp::initialize();
  
  return fuse_main(argc, argv, &ivl::httpsfs::ops, nullptr);
}

# include-https
Weird hack for `#include`-ing files over https  
Tested only with github raw stuff  
Use at your own risk  

## Usage
This section assumes you've successfully installed this  
  
To include a file located at `https://<REST-OF-URL>`:
```
#include <https://<REST-OF-URL>>
// or
#include "https://<REST-OF-URL>"
```
To add a `<URL>` as a directory for header/library searching add flag:
```
-idirafter "/usr/include/<URL>"
# or
-iprefix "/usr/include/" -iwithprefix "<URL>"
```

## Install - all steps
```
sudo apt install libfuse3-dev
sudo apt install libcurlpp-dev
./build.sh && ./install.sh
```

## Examples
TODO

## Requirements
```
sudo apt install libfuse3-dev
sudo apt install libcurlpp-dev
```

## Build
```
./build.sh
```

## Install
```
./install.sh
```

## Uninstall
```
./uninstall.sh
```

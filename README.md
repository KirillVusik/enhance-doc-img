# enhance-doc-img
Attempt to enhance scanned documents images

## Prerequisites
* Cmake >= 3.10
* Conan Package Manager (https://conan.io/):  
If you have a Python installed, the simplest way to install it is to run 
```pip install conan```
* C++ compiler with C++11 support 

## Tested environment
OS: Ubuntu 18.04 and Windows 10
Compilers: gcc 7.4.0 and msvc 19.16

## Build (Windows)
1. Install Visual Studio C++ Build Tools  
You can download them from https://visualstudio.microsoft.com  
or  
use *chocatey* (https://chocolatey.org/install): 
```choco install visualcpp-build-tools```
2. Open Developer Tools Command Prompt installed with Build Tools
3. Create a *build* directory under the repository root and cd to it, e.g.:  
```cd <repo_path>```  
```md build && cd build```
4. Generate NMake files by running the following command:  
```cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release ..```
5. Run nmake:  
```nmake```

## Build (Linux)
1. Make sure that gcc with C++11 support is installed, otherwise install it e.g. with *apt*
2. Make sure that required gcc compiler is set for CMake (e.g., you can use CXX environment variable) 
3. Create a *build* directory under the repository root and cd to it, e.g.:  
```cd <repo_path>```  
```mkdir build && cd build```
4. Generate Unix Makefiles files by running the following command:
```cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..```
5. Run make:  
```make```
   
### Run application:
The binary *client_app* is located under the <repo_path>/build/client_app/bin directory
This app expects two input arguments:  
```client_app SOURCE_FILE DESTINATION_FILE```


# f-control Example

# How to use
Download prject and run:
```
cd fcontrol-example
./script/bootstrap
```
Then use your favorite CMake deployment system.

# Dependencies
The example needs libplot-dev in order to show graphs. 
You can install under a debian based linux with:
```
sudo apt install libplot-dev
```

The library is intended for the use with CMake build system. CmakeLists.txt is configured to search for the following dependencies as required:
* fftw
* eigen

You can install under a debian based linux with:
```
sudo apt install fftw-dev libeigen3-dev
```
For ubuntu 18.04 LTS you need FFTW3 library
```
sudo  apt-get install libfftw3-dev
```


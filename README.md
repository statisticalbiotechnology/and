# Percolator Installation Notes

##   Background

This repository contains thoughts about what may be hard to know when installing the software, or building it directly via CMake. These inslallation notes are made with the assumption that a Unix operating system is used. The process may be different on Windows. It is also assumed that the user has basic knowledge of terminal commands.

##  Software
The following installations need to be made prior to manually building the source code:

```
sudo apt-get install cmake
sudo apt-get update
sudo apt-get upgrade
sudo apt-get update cmake
sudo apt-get install g++
sudo apt-get install libboost-all-dev
sudo apt-get install xsdcxx
sudo apt-get install sqlite3 libsqlite3-dev
```
Additionally, the latest version of Xerces-C++ must be retrieved manually, as apt-get only retrieves version 3.2.0, whilst 3.2.3 is seems necessary. To get the latest version do the following:


```
wget http://apache.mirrors.spacedump.net//xerces/c/3/sources/xerces-c-3.2.3.zip
unzip xerces-c-3.2.3.zip 
mkdir buildXerces && cd buildXerces
cmake ../xerces-c-3.2.3/
sudo make install
```


##  Building

There are shell scripts under <mark style="background:gray">/admin/builders/</mark> for automatic installation. One options is therefore to simply run the script named with the OS you are using.

Another option, and also the preferred way of doing it, is to manually build through CMake and Make. The repository comes with several individual modules that can be built independently. There are two main modules that are needed for normal runs, namely "perculator" and "converters". perculator build files are found in the root directory <mark style="background:gray">/</mark> and converters under <mark style="background:gray">/src/converters/</mark> . Directly use CMake with those directories from where you chose to build. Don't build in the same directory as the source files. CMake have [flags](https://cmake.org/cmake/help/v3.6/manual/cmake.1.html) that can be set to enable for instance debug-information or accompanying unit tests.




<p align="left" vertical-align="bottom">
E-mail contact <a href="mailto:marcus.andersson@scilifelab.se">here</a>.
</p>

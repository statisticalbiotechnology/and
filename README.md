# Percolator Installation Notes

##   Background

This repository contains thoughts about what may be hard to know when installing the software, or building it directly via CMake. These inslallation notes are made with the assumption that a Unix operating system is used. The process may be different on Windows. It is also assumed that the user has basic knowledge of terminal commands.

##  Software
The following installations need to be made prior to manually building the source code:

```shell
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


```shell
wget http://apache.mirrors.spacedump.net//xerces/c/3/sources/xerces-c-3.2.3.zip
unzip xerces-c-3.2.3.zip 
mkdir buildXerces && cd buildXerces
cmake ../xerces-c-3.2.3/
sudo make install
```


<p align="left" vertical-align="bottom">
E-mail contact <a href="mailto:marcus.andersson@scilifelab.se">here</a>.
</p>

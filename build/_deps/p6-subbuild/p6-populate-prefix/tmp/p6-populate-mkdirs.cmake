# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-src"
  "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build"
  "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix"
  "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/tmp"
  "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp"
  "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src"
  "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

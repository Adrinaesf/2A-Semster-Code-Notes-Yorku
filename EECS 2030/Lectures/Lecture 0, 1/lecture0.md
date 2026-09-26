# Advanced Object Oriented Programming:
Otline of today's class:
1. Course theme in EECS 1022, EECS 2030


# Packages:
* All Java API classes are in a package called Java. 
* Packages can have a nesting structure --> Having sub-packages:
    * Example: under java we have: java.lang, java.util, or java.lang.Math 

* For more info take a look at: https://dm7crvy4e45rz.cloudfront.net/63/60/6360219a3d2b22da9b942de1a834fc4a1ed7cc7f?response-content-disposition=inline%3Bfilename%3D%2226f%20L1%20--%20current%20post%20--%20EECS2030A-F2019-L1-IntroductionX.pdf%22&response-content-type=application%2Fpdf&Expires=1789095300&Signature=tfVVAOTvH964v1MT~bZx3Ehu2c5DM8TrOp3FeGLKC9ZUAs4bf0CxEq~0D8dWpNg1hQ6XPv3lIAobG2YFbIqhjUAmm5iZb7DcJGShJ21ZosItCLP70bG7aPzjfxH2Zmiz415c6qjIdrpnktiJ5EaSRcl2feQdjKvKaL5rAgnbSBYWONBbGJVrzshw~taghgjOEsn1tmHwv3Dt9NnKVTkrWKmf6Tg8dAJyKHI0yK8iY12JkGTVIvqXofyRHBfTjYynxi0wF0jXPMlL2SYbUrI4f1Pe-CsIbpZpSbChwlD7IoZdVihKllMgGSWhEak3mFwn9r53QViWNdrxpe-pAf4Uyw__&Key-Pair-Id=K5YOCTGPV4CPX 

* Syntax:
    * package <top_pkg_name>[.<sub_pkg_name>]*;
    * Example: package java.lang; package java.util;
    * Packaging is mainly used to organize your code. 
    

* Only one package declaration per source file
* If no package name is declared → the class is placed
into an unnamed package -- the default package
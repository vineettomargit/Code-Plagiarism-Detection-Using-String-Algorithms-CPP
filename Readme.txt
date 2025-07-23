vineettomar@Vineets-Mac-mini src % clang++ -std=gnu++14 -fcolor-diagnostics -fansi-escape-codes -g \
/Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/main.cpp \
/Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/SimilarityFacade.cpp \
/Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/NGram.cpp \
/Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/KMP.cpp \
/Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/RabinKarp.cpp \
/Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/SuffixArray.cpp \
/Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/EditDistance.cpp \
-o /Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/main
vineettomar@Vineets-Mac-mini src % /Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/main fileA.cpp fileB.cpp
N-gram Jaccard       : 1.000
KMP sample match     : 1.000
Rabin-Karp sample    : 1.000
Suffix-array sample  : 1.000
Edit-distance (norm) : 1.000
vineettomar@Vineets-Mac-mini src % 


vineettomar@Vineets-Mac-mini src % /Users/vineettomar/LocalDisk/Project_CPP/CodePlagrismDetectionUsingStringAlgorithms/src/main fileA.cpp fileB.cpp
N-gram Jaccard       : 0.303
KMP sample match     : 0.700
Rabin-Karp sample    : 0.900
Suffix-array sample  : 1.000
Edit-distance (norm) : 0.262
vineettomar@Vineets-Mac-mini src % 
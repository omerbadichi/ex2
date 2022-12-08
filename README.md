# ex2
In our second assignment we were asked to classify a given vector based on the machine learning method: KNN.
## KNN:
In order to teach the machine about certain data type,for example a cat, we will first need to classify a lot of images "by hand"(i.e by man)
and classify them on weahther their is a cat in the image or not.

We then will upload our classified data to our algorithm ,for it to "learn" certain characters about the images containing a cat ,and the 
ones who dont.And now,if given a new image that doesnt have classification, our algorithm will classify the image based on the characters it 
"learned" from our classify data.

In our project this method classify a certain data, represented by a vector. The method compare the distances between our data vector to its
already classified vectors, and return the most popular classification among the k(an integer) vectors with the smallest distance between ours.

## Input:
Our program asks from the user to enter a vector, and it classify at by using its already classified data.

Invalid input contains: vector with a different size than our classified vectors, vector that one of its arguments isnt a valid double,
empty vector and etc.

The only valid input is doubled numbers seperated by whitespaces(no limit on the number of numbers).

## Output:
We return the classification for our given vector, based on his K neighbors(the vectors with the short distance to it).

For more data about KNN algorithm, we recomand to read:https://he.wikipedia.org/wiki/%D7%90%D7%9C%D7%92%D7%95%D7%A8%D7%99%D7%AA%D7%9D_%D7%A9%D7%9B%D7%9F_%D7%A7%D7%A8%D7%95%D7%91

# The flow of the program:

We start with a series of checks on the validation of the arguments given in the command line:

    1)If the k given is a positive integer number.
    
    2)If the path is valid and contains a classified data stored in a file.
    
    3)If the Norm(a way to calculate distance between vectors) is valid, i.e "AUC"(Euclidean distance)/"MAN"(Manhatten distance)/"CHB"(Chebyshev distance)/
    "CAN"(Canberra distance) or "MIN"(Minkowski distance).
    
We than recive from the user a valid vector, and calculate the distance based on the norm he given us to all our classified vectors,
we than sort our vectors in an ascending order, and from the K(the number from the command line) vectors with the shortest distance(the users vector neighbors)
we find the most popular classification, and we return it as the classification of the user vector.

# How to compile and run:

First, clone this repository. Then there are two ways:

##### 1) Using makefile:
         a) Open the project folder in the terminal and type in 'make' and start to
         follow the programs orders.
         b)Than write in the command line:
         ./a.out [k(a positive integer)] [path(the address of the classified file)] [Norm(a way to calculate distance between vectors)] 
         c) In order to clean the exe and o files, type 'make clean' in terminal.        

##### 2) Writing the orders manualy:
        a)Open the project folder in the terminal and type in these orders:
        b)g++ -std=c++11 *.cpp -o a.out
        c)Than write in the command line:
        **./a.out [k(a positive integer)] [path(the address of the classified file)] [Norm(a way to calculate distance betweenvectors)]** 
        d)In order to clean the exe and o files,type:
          1)rm -rf *.o
          2)rm -rf a.out

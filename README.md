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
# How to compile and run:
In order to make the proccess easier we made a makefile project, and all that is left to do is to type "make".

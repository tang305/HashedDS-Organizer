Use the input data file as input to enter data into a hash table. Hash table should have as many entries as the data items in the file. The birthday should be used as the hash key by adding the digits repeatedly until it ends up being a number between 0 and 9, which will be the index of the data in the hash table. So, a date of 2017-12-04 will reduce as 2+0+1+7+1+2+0+4 = 17 which will further reduce as 1+7 = 8 and its associated data record (name + birthday) will be added to index 8 in the hash table. If you used any other format of date in Lab 5, you are allowed to fix the date to this format. For collision resolution, use quadratic probing in the same direction always. Your main will first load the data file into the hash table and print the number of data items loaded, load factor and number of collisions.  Then it will ask the user in a loop to enter a birthdate - any date. If the birthdate is found in the hash table, it will print the name associated with that date, otherwise it will print 'Invalid Data'. Then it will ask the user if they want to check again or end the program.

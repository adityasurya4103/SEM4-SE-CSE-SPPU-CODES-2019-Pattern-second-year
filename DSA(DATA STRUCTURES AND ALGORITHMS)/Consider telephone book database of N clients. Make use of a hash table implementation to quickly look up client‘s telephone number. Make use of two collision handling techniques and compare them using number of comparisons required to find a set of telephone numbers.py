class Record:
    def __init__(self):
      self._number = None
      self._name=None

    def get_number(self):
        return self._number

    def set_number(self,number):
        self._number = number

    def get_name(self):
        return self._name

    def set_name(self,name):
        self._name = name

    def __str__(self):
        record = "Name: "+str(self.get_name())+" Number: "+str(self.get_number())
        return record

        


class hashTable:
    # initialize hash Table
    def __init__(self):
        self.size = int(input("Enter the Size of the hash table : "))
        # initialize table with all elements 0
        self.table = list(None for i in range(self.size))
        self.elementCount = 0
        self.comparisons = 0
   
   
    # method that checks if the hash table is full or not
    def isFull(self):
        if self.elementCount == self.size:
            return True
        else:
            return False
   
   
    # method that returns position for a given element
    def hashFunction(self, element):
        return element % self.size
       
   
    # method that inserts element into the hash table
    def insert(self, record):
        # checking if the table is full
        if self.isFull():
            print("Hash Table Full")
            return False
           
        isStored = False
       
        position = self.hashFunction(record.get_number())
       
        # checking if the position is empty
        if self.table[position] == None:
            self.table[position] = record
            print("Number inserted  is at position " + str(position))
            isStored = True
            self.elementCount += 1
       
        # collision occured hence we do linear probing
        else:
            print("Collision has occured for number at position " + str(position) + " finding new Position.")
            while self.table[position] != None:
                position += 1
                if position >= self.size:
                    position = 0
           
            self.table[position] = record
            print(" number is at position " + str(position))
            isStored = True
            self.elementCount += 1
        return isStored
       
 
    
                               
 
    # method to display the hash table
    def display(self):
        print("\n")
        for i in range(self.size):
             print("Hash Value: "+str(i) + "\t\t" + str(self.table[i]))
        print("The numbers are : " + str(self.elementCount))

    
def input_record():
    record = Record()
    name=input("Enter your Name:    ")
    number = int(input("Enter Number:"))
    record.set_name(name)
    record.set_number(number)
    return record    

print("1. Linear Probing      *")
h1 = hashTable()   
    
choice2 = 0
while(choice2 != 4):
            print("************************")
            print("1. Insert              *")
            print("2. Search              *")
            print("3. Display             *")
            print("4. Back                *")
            print("************************")

            choice2 = int(input("Enter Choice"))
            if choice2>4:
                 print("Please Enter Valid Choice")

            if(choice2==1):
                record = input_record()
                h1.insert(record)

            elif(choice2 == 3):
                h1.display()

        

    

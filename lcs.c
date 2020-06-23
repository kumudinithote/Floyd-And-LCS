#include <stdio.h>
#include <string.h>

#define max(x,y) ((x) >= (y)) ? (x) : (y)

void lcs(char *firstWord, char *secondWord, int size_of_firstWord, int size_of_secondWord ) {
  int Matrix[size_of_firstWord+1][size_of_secondWord+1];

  //Build matix
  for (int i=0; i<=size_of_firstWord; i++)
   {
     for (int j=0; j<=size_of_secondWord; j++)
     {
       if (i == 0 || j == 0)
         Matrix[i][j] = 0;
       else if (firstWord[i-1] == secondWord[j-1])
         Matrix[i][j] = Matrix[i-1][j-1] + 1;
       else
         Matrix[i][j] = max(Matrix[i-1][j], Matrix[i][j-1]);
     }
   }

   // Following code is used to print LCS
   int index = Matrix[size_of_firstWord][size_of_secondWord];

   // Create a character array to store the lcs string
   char solution[index+1];
   solution[index] = '\0'; // Set the terminating character

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = size_of_firstWord, j = size_of_secondWord;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (firstWord[i-1] == secondWord[j-1])
      {
          solution[index-1] = firstWord[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (Matrix[i-1][j] > Matrix[i][j-1])
         i--;
      else
         j--;
   }
   printf("Size of Longest common subsequence is : %d\n", Matrix[size_of_firstWord][size_of_secondWord]);
   printf("Longest common subsequence is : %s\n", solution);
}

int main(int argc,char* argv[]){
  char *strOne;
  char *strTwo;

  if(argc==2){
    printf("Please give 2 strings to get longest common subsequence\n");
    return -1;
  }
  else if(argc==3)
  {
    strOne = argv[1];
    strTwo = argv[2];
  }
  else{
    printf("Not more than 2 strings are allowed.\n");
    return -1;
  }

  int size_of_firstWord = strlen(strOne);
  int size_of_secondWord = strlen(strTwo);

	printf("First word is : %s\n",strOne);
  printf("second word is : %s\n",strTwo);

  lcs(strOne,strTwo, size_of_firstWord, size_of_secondWord);
	return 0;
}

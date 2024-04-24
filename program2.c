#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define LR 1
// #define LL 0
// #define UR 2
// #define UL 3
// #define MS -1

# define Max 256
int board[Max][Max];

void tromino /* function to do tiling */
     ( int x_board,      /* x coordinate of board */
       int y_board,      /* y coordinate of board */
       int x_missing,    /* x coordinate of missing square */   //given
       int y_missing,    /* y coordinate of missing square */
       int board_size);   /* size of board */

void show_Tromino(int size, int x_miss, int y_miss);

int main()
{
     int board_size,
         x_missing,  /* x coordinate of missing square */
         y_missing;  /* y coordinate of missing square */
     do {
          printf( "\n" );
          printf( "\nEnter size of board (0 to quit): " );
          scanf( "%d", &board_size );
          if(board_size==0 || board_size==1 || board_size<0)
            exit(0);
          if ( (ceil(log2(board_size)) == floor(log2(board_size))) ) {
               printf( "\nPlease enter coordinates of missing square (separate by a space): " );
               scanf( "%d%d", &x_missing, &y_missing );
               if(x_missing<0 || x_missing>=board_size || y_missing<0 || y_missing>= board_size){
               printf("\n ERROR: Coordinates of missing tile are not correct \n");
               exit(0);
               }
               printf( "\n Tromino Tiling Below : \n" );
               // if(board[x_board][0] == x_missing && board[0][y_board] == y_missing)
               //  printf("MS\t");
               //board[x_missing][y_missing] = -1;
               tromino( 0, 0, x_missing, y_missing, board_size);
               show_Tromino(board_size, x_missing, y_missing);
          }
       else{
         printf("\n ERROR : Enter size of board in power of 2 \n");
            exit(0);}
     } while ( board_size );

     return EXIT_SUCCESS;
}

void tromino( int x_board,     /* x coordinate of board */
              int y_board,     /* y coordinate of board */
              int x_missing,   /* x coordinate of missing square */
              int y_missing,   /* y coordinate of missing square */
              int board_size) /* size of board, which is a power of 2*/

{
     
     if ( board_size == 2 ) /* 2x2 board */
     {
       if(x_board==x_missing && y_board==y_missing)
         board[x_board+1][y_board] = board[x_board][y_board+1]=board[x_board+1][y_board+1]= 2 ; //2=UR

       if(x_board+1==x_missing && y_board==y_missing)
         board[x_board][y_board]= board[x_board][y_board+1]=board[x_board+1][y_board+1]=3; //3 = UL

       if(x_board==x_missing && y_board+1==y_missing)
         board[x_board][y_board]= board[x_board+1][y_board] = board[x_board+1][y_board+1]=1; //1=LR

       if(x_board+1==x_missing && y_board+1==y_missing)
         board[x_board][y_board]= board[x_board+1][y_board] = board[x_board][y_board+1]= 0; // 0 = LL
       return;
     }
       // if(board_size>2)
  else{
  int half_size = board_size/2, /* size of subboard */
         x_center,  /* x coordinate of center of board */
         y_center,  /* y coordinate of center of board */
         x_upper_left,  /* x coordinate of missing square in upper left subboard */
         y_upper_left,  /* y coordinate of missing square in upper left subboard */
         x_upper_right, /* x coordinate of missing square in upper right subboard */
         y_upper_right, /* y coordinate of missing square in upper right subboard */
         x_lower_right, /* x coordinate of missing square in lower right subboard */
         y_lower_right, /* y coordinate of missing square in lower right subboard */
         x_lower_left,  /* x coordinate of missing square in lower left subboard */
         y_lower_left;  /* y coordinate of missing square in lower left subboard */

// { when board size is >2   /* compute x and y coordinates of center of board */
   
     x_center = x_board + half_size;
     y_center = y_board + half_size;

      // printf("\n half size = ",half_size);
      // printf("\n x_center = ",x_board);
      // printf("\n y_center = ", y_center,"\n");
         if((x_missing < x_center) && (y_missing < y_center))
         {
           //printf("UR\t");
           x_upper_left = x_center - 1;
           y_upper_left = y_center;
           x_upper_right = x_center;
           y_upper_right = y_center;
           x_lower_left = x_missing;
           y_lower_left = y_missing;
           x_lower_right = x_center;
           y_lower_right = y_center - 1;
           board[x_upper_left][y_upper_left]=2;     
           board[x_upper_right][y_upper_right]=2;
           board[x_lower_right][y_lower_right]=2;

         }
         if((x_missing >= x_center) && (y_missing < y_center))
         {
           //printf("UL\t");
           x_upper_left = x_center - 1;
           y_upper_left = y_center;
           x_upper_right = x_center;
           y_upper_right = y_center;
           x_lower_left = x_center - 1;
           y_lower_left = y_center - 1;
           x_lower_right = x_missing;
           y_lower_right = y_missing;
           board[x_upper_left][y_upper_left]=3;     
           board[x_upper_right][y_upper_right]=3;
           board[x_lower_left][y_lower_left]=3;
         }
         if((x_missing >= x_center) && (y_missing >= y_center))
         {
           //printf("LL\t");
           x_upper_left = x_center - 1;
           y_upper_left = y_center;
           x_upper_right = x_missing;
           y_upper_right = y_missing;
           x_lower_left = x_center - 1;
           y_lower_left = y_center - 1;
           x_lower_right = x_center;
           y_lower_right = y_center - 1;
           board[x_upper_left][y_upper_left]=0;     
           board[x_lower_left][y_lower_left]=0;
           board[x_lower_right][y_lower_right]=0;
         }
         if((x_missing < x_center) && (y_missing >= y_center))
         {
           //printf("LR\t");
           x_upper_left = x_missing;
           y_upper_left = y_missing ;
           x_upper_right = x_center;
           y_upper_right = y_center;
           x_lower_left = x_center - 1;
           y_lower_left = y_center - 1;
           x_lower_right = x_center;
           y_lower_right = y_center - 1;
           board[x_lower_left][y_lower_left]=1;  //center
           board[x_upper_right][y_upper_right]=1;
           board[x_lower_right][y_lower_right]=1;
         }
     /* tile the four subboards */
     tromino( x_board, y_board + half_size,
          x_upper_left, y_upper_left, half_size);
     tromino( x_board + half_size, y_board + half_size,        //given
          x_upper_right, y_upper_right, half_size);
     tromino( x_board + half_size, y_board,
          x_lower_right, y_lower_right, half_size);
     tromino( x_board, y_board,
                    x_lower_left, y_lower_left, half_size);

    }
}

void show_Tromino(int size, int x_miss, int y_miss)
{
  printf("\n");
  for(int i=size-1;i>=0;i--)
  {
     for(int j=0; j<size;j++)
     {
       if(j==x_miss && i==y_miss)
        printf(" MS ");
       else
       { if(board[j][i]==1)
         printf(" LR ");
         if(board[j][i]==3)
           printf(" UL ");
         if(board[j][i]==2)
           printf(" UR ");
         if(board[j][i]==0)
           printf(" LL ");
        
        
       }
    }
    printf("\n");
  }

}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ACCEPT_CHALLENGE 0

#if ACCEPT_CHALLENGE == 0

#define M 32
#define N 256
#define LOGN 8

#else

#define M 4096
#define N 65536
#define LOGN 16

#endif 

void printbin( int a, int len ){
   if ( a != -1 ){
       for ( int i =1; i <= len ; i++ ){
           printf("%d",(a>>(len-i)&1));
       }
   } else {
       for ( int i =1; i <= len ; i++ ){
           printf(" ");
       }
   }
}

int to_grey(int a ){
    a = ( a >> 1 ) ^ a ;
    return a;
}

int count_ones( int a , int len ){

   int ones;

   ones = 0;
   for ( int i =1; i <= len ; i++ ){
       ones += (a>>(len-i)&1) ;
   }

   return ones;
}


void generate_bases( int ** bases ){

    bases[0][0]  =   0; bases[1][0]  =   1; bases[2][0]  =   2; bases[3][0]  =   3;
    bases[0][1]  =   7; bases[1][1]  =   6; bases[2][1]  =   5; bases[3][1]  =   4;
    bases[0][2]  =  25; bases[1][2]  =  24; bases[2][2]  =  27; bases[3][2]  =  26;
    bases[0][3]  =  30; bases[1][3]  =  31; bases[2][3]  =  28; bases[3][3]  =  29;
    bases[0][4]  =  42; bases[1][4]  =  43; bases[2][4]  =  40; bases[3][4]  =  41;
    bases[0][5]  =  45; bases[1][5]  =  44; bases[2][5]  =  47; bases[3][5]  =  46; 
    bases[0][6]  =  51; bases[1][6]  =  50; bases[2][6]  =  49; bases[3][6]  =  48;
    bases[0][7]  =  52; bases[1][7]  =  53; bases[2][7]  =  54; bases[3][7]  =  55;
    bases[0][8]  =  75; bases[1][8]  =  74; bases[2][8]  =  73; bases[3][8]  =  72;
    bases[0][9]  =  76; bases[1][9]  =  77; bases[2][9]  =  78; bases[3][9]  =  79;
    bases[0][10] =  82; bases[1][10] =  83; bases[2][10] =  80; bases[3][10] =  81;
    bases[0][11] =  85; bases[1][11] =  84; bases[2][11] =  87; bases[3][11] =  86;
    bases[0][12] =  97; bases[1][12] =  96; bases[2][12] =  99; bases[3][12] =  98;
    bases[0][13] = 102; bases[1][13] = 103; bases[2][13] = 100; bases[3][13] = 101;
    bases[0][14] = 120; bases[1][14] = 121; bases[2][14] = 122; bases[3][14] = 123;
    bases[0][15] = 127; bases[1][15] = 126; bases[2][15] = 125; bases[3][15] = 124;
    bases[0][16] = 255; bases[1][16] = 254; bases[2][16] = 253; bases[3][16] = 252;
    bases[0][17] = 248; bases[1][17] = 249; bases[2][17] = 250; bases[3][17] = 251;
    bases[0][18] = 230; bases[1][18] = 231; bases[2][18] = 228; bases[3][18] = 229;
    bases[0][19] = 225; bases[1][19] = 224; bases[2][19] = 227; bases[3][19] = 226;
    bases[0][20] = 213; bases[1][20] = 212; bases[2][20] = 215; bases[3][20] = 214;
    bases[0][21] = 210; bases[1][21] = 211; bases[2][21] = 208; bases[3][21] = 209;
    bases[0][22] = 204; bases[1][22] = 205; bases[2][22] = 206; bases[3][22] = 207;
    bases[0][23] = 203; bases[1][23] = 202; bases[2][23] = 201; bases[3][23] = 200;
    bases[0][24] = 180; bases[1][24] = 181; bases[2][24] = 182; bases[3][24] = 183;
    bases[0][25] = 179; bases[1][25] = 178; bases[2][25] = 177; bases[3][25] = 176;
    bases[0][26] = 173; bases[1][26] = 172; bases[2][26] = 175; bases[3][26] = 174;
    bases[0][27] = 170; bases[1][27] = 171; bases[2][27] = 168; bases[3][27] = 169;
    bases[0][28] = 158; bases[1][28] = 159; bases[2][28] = 156; bases[3][28] = 157;
    bases[0][29] = 153; bases[1][29] = 152; bases[2][29] = 155; bases[3][29] = 154;
    bases[0][30] = 135; bases[1][30] = 134; bases[2][30] = 133; bases[3][30] = 132;
    bases[0][31] = 128; bases[1][31] = 129; bases[2][31] = 130; bases[3][31] = 131;
     
    bases[4][0]  =   8; bases[5][0]  =   9; bases[6][0]  =  10; bases[7][0]  =  11;
    bases[4][1]  =  15; bases[5][1]  =  14; bases[6][1]  =  13; bases[7][1]  =  12;
    bases[4][2]  =  17; bases[5][2]  =  16; bases[6][2]  =  19; bases[7][2]  =  18;
    bases[4][3]  =  22; bases[5][3]  =  23; bases[6][3]  =  20; bases[7][3]  =  21;
    bases[4][4]  =  34; bases[5][4]  =  35; bases[6][4]  =  32; bases[7][4]  =  33;
    bases[4][5]  =  37; bases[5][5]  =  36; bases[6][5]  =  39; bases[7][5]  =  38;
    bases[4][6]  =  59; bases[5][6]  =  58; bases[6][6]  =  57; bases[7][6]  =  56;
    bases[4][7]  =  60; bases[5][7]  =  61; bases[6][7]  =  62; bases[7][7]  =  63;
    bases[4][8]  =  67; bases[5][8]  =  66; bases[6][8]  =  65; bases[7][8]  =  64;
    bases[4][9]  =  68; bases[5][9]  =  69; bases[6][9]  =  70; bases[7][9]  =  71;
    bases[4][10] =  90; bases[5][10] =  91; bases[6][10] =  88; bases[7][10] =  89;
    bases[4][11] =  93; bases[5][11] =  92; bases[6][11] =  95; bases[7][11] =  94;
    bases[4][12] = 105; bases[5][12] = 104; bases[6][12] = 107; bases[7][12] = 106;   
    bases[4][13] = 110; bases[5][13] = 111; bases[6][13] = 108; bases[7][13] = 109;
    bases[4][14] = 112; bases[5][14] = 113; bases[6][14] = 114; bases[7][14] = 115;
    bases[4][15] = 119; bases[5][15] = 118; bases[6][15] = 117; bases[7][15] = 116;
    bases[4][16] = 247; bases[5][16] = 246; bases[6][16] = 245; bases[7][16] = 244;
    bases[4][17] = 240; bases[5][17] = 241; bases[6][17] = 242; bases[7][17] = 243;
    bases[4][18] = 238; bases[5][18] = 239; bases[6][18] = 236; bases[7][18] = 237;
    bases[4][19] = 233; bases[5][19] = 232; bases[6][19] = 235; bases[7][19] = 234;
    bases[4][20] = 221; bases[5][20] = 220; bases[6][20] = 223; bases[7][20] = 222;
    bases[4][21] = 218; bases[5][21] = 219; bases[6][21] = 216; bases[7][21] = 217;
    bases[4][22] = 196; bases[5][22] = 197; bases[6][22] = 198; bases[7][22] = 199;
    bases[4][23] = 195; bases[5][23] = 194; bases[6][23] = 193; bases[7][23] = 192;
    bases[4][24] = 188; bases[5][24] = 189; bases[6][24] = 190; bases[7][24] = 191;
    bases[4][25] = 187; bases[5][25] = 186; bases[6][25] = 185; bases[7][25] = 184;
    bases[4][26] = 165; bases[5][26] = 164; bases[6][26] = 167; bases[7][26] = 166;
    bases[4][27] = 162; bases[5][27] = 163; bases[6][27] = 160; bases[7][27] = 161;
    bases[4][28] = 150; bases[5][28] = 151; bases[6][28] = 148; bases[7][28] = 149;
    bases[4][29] = 145; bases[5][29] = 144; bases[6][29] = 147; bases[7][29] = 146;
    bases[4][30] = 143; bases[5][30] = 142; bases[6][30] = 141; bases[7][30] = 140;
    bases[4][31] = 136; bases[5][31] = 137; bases[6][31] = 138; bases[7][31] = 139;  
   
    return;

}


int main(){

   int i, j, k ;
   int basei, basej, one_cnt, error, occurrance;
   int ** bases;

   bases = (int **) malloc(LOGN*sizeof(int *));
   for ( i = 0 ; i < LOGN ; i++ ) bases[i] = (int *) malloc(M*sizeof(int));

   // your soulution here
   generate_bases( bases );

   //check hamming distance
   error = 0;
   for ( basei = 0; (basei < LOGN) && (!error); basei++ ){

       printf("checking base %4d\n",basei);

       for ( k = 0; (k < N) && (!error); k++ ){
           error = 1;
           for ( basej = 0; basej < M; basej++ ){
               one_cnt = count_ones( k ^ bases[basei][basej], LOGN);
               if (( one_cnt == 0 )||( one_cnt == 1 )){
                    error = 0;
               }
           }
           if ( error == 1 ){
               printf("error in base %4d, counter example %4d ",basei,k);
               printbin(k,LOGN);
               printf("\n");

               // print base
               for ( i = basei; i == basei ; i++ ){
                   for ( j = 0; j < M ; j++ ){
                       printbin(bases[i][j],LOGN);
                       printf(" ");
                   }
                   printf("\n");
               }
               printf("\n");
           }
       }
   }

   //check unicity
   for ( i = 0; (i < N) && ( ! error ); i++ ){
       occurrance = 0;
       for ( basei = 0; (basei < LOGN) && (!error); basei++ ){
           for ( basej = 0; basej < M; basej++ ){
               if ( bases[basei][basej] == i ){
                   occurrance ++;
               }
           }
        }
        if ( occurrance != 1 ){
             error = 1;
        }
   }

   if ( error == 0 ){
       // print bases
       printf("\n\nvalid bases:\n");
       for ( i = 0; i < LOGN ; i++ ){
           for ( j = 0; j < M ; j++ ){
                printf("%4d, ",bases[i][j]);
                //printbin(bases[i][j],LOGN);
                printf(" ");
                if ( j == M/2-1){
                    printf("\n");
                }
           }
           printf("\n\n");
       }
       printf("\n");
   } else {
       printf("not valid bases\n");
   }

   for ( i = 0 ; i < LOGN ; i++ ) free(bases[i]) ;
   free(bases);

   return 0;

}






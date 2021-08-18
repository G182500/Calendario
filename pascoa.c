#include<stdio.h>
int main(){
   //Declarações
   int i,semana,fc1,fc2,ano,naureo,sec,epacta,lua,domingopascoa,ano2,bissexto,datapascoa;
   //Entrada
   printf("Digite o ano:");
   scanf("%d",&ano);
   //-----------------------------------
   //Calculos para descobrir datapascoa
   naureo=(ano%19)+1;
   sec=(ano/100)+1;
   fc1=(((3*sec)/4)-12);
   fc2=((((8*sec)+5)/25)-5);
   epacta=((11*naureo)+20+fc2-fc1)%30;
   
   if(((epacta==25)&&(naureo>11))||(epacta==24)){
      epacta=epacta+1;
   }
  
   lua=44-epacta;
   
   if(lua<21){
      lua=lua+30;
   }
   
   domingopascoa=(((5*ano)/4)-(fc1+10));
   lua=(lua+7)-((domingopascoa+lua)%7);
   
   if(lua>31){
      datapascoa=lua-31; //de abril
   }
   else{
      datapascoa=lua; //de marco
   }
   //-----------------------------------
   //Calculos para descobrir se bissexto eh 0 ou 1
   ano2=ano;
   
   if((ano2%100)==0){
      ano2=ano2/100;
   }
   if((ano2%4)==0){
      bissexto=1; //Eh bissexto
   }
   if((ano2%4)!=0){
      bissexto=0; //N eh bissexto
   }
   //----------------------------------
   //Calculos para descobrir o primeiro dia da semana de janeiro
   semana=1;
   
   if(bissexto==0){
      if(datapascoa==lua){ //de marco
         for(i=datapascoa;i>1;i--){
            semana--;
            if(semana==0){
            semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=28;i>1;i--){ //fevereiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=31;i>1;i--){ //janeiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
      }
      
      else{ //de abril
         for(i=datapascoa;i>1;i--){
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=31;i>1;i--){ //marco
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=28;i>1;i--){ //fevereiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=31;i>1;i--){ //janeiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
      }
   }
   //----------------------------------
   else{ //bissexto
      if(datapascoa==lua){ //de marco
         for(i=datapascoa;i>1;i--){
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=29;i>1;i--){ //fevereiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=31;i>1;i--){ //janeiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
      }
      
      else{ //de abril
         for(i=datapascoa;i>1;i--){
            semana--;
           if(semana==0){
            semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=31;i>1;i--){ //marco
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=29;i>1;i--){ //fevereiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
         if(semana>1){semana--;}
         else{semana=7;}
         for(i=31;i>1;i--){ //janeiro
            semana--;
            if(semana==0){
               semana=7;
            }
         }
      }
   }
  //----------------------------------
  //Exibicao do calendario
   int t,j,k,l=0,m;

   printf("Calendario do ano %d",ano);
   printf("\n|-----------------------------|\n");

   for(i=1;i<=12;i++){
   l=0;
   if(i==1){
   printf("|Janeiro                      |\n");
   t=31;
   }
   if(i==2){
   printf("|Fevereiro                    |\n");
   if(bissexto==0){t=28;}
   if(bissexto==1){t=29;}
   }
   if(i==3){
   printf("|Março                        |\n");
   t=31;
   }
   if(i==4){
   printf("|Abril                        |\n");
   t=30;
   }
   if(i==5){
   printf("|Maio                         |\n");
   t=31;
   }
   if(i==6){
   printf("|Junho                        |\n");
   t=30;
   }
   if(i==7){
   printf("|Julho                        |\n");
   t=31;
   }
   if(i==8){
   printf("|Agosto                       |\n");
   t=31;
   }
   if(i==9){
   printf("|Setembro                     |\n");
   t=30;
   }
   if(i==10){
   printf("|Outubro                      |\n");
   t=31;
   }
   if(i==11){
   printf("|Novembro                     |\n");
   t=30;
   }
   if(i==12){
   printf("|Dezembro                     |\n");
   t=31;
   }

   printf("|-----------------------------|\n");
   printf("| dom seg ter qua qui sex sab |\n");
   printf("|");
   m=1;
   for(j=1;j<=42;j++){
   if(j<semana){printf("  --");l++;}
   if((j>=semana)&&((j-l)<=t)){printf("  %02d",j-l);}
   if((j-l)==t){k=m+1;}
   if((j-l)>t){printf("  --");}
   if(j%7==0){printf(" |\n|");m=0;}
   m++;
   }
   if(k<8){semana=k;}
   if(k==8){semana=1;}
   printf("-----------------------------|\n");
   }

   return 0;
}

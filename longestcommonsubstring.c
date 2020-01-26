#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LARGE 255
#define PRIME 43
struct Node{
  int data;
  struct Node *next;
};

struct Node *InsertatBeg(struct Node **head , int data){
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next= *head;
  *head = temp;
  return temp;
}

void traverse_list(struct Node *head){
  while(head!=NULL){
    printf("%d-->" , head->data);
    head = head->next;
  }printf("NULL\n");
}

int check_substring(char *num1 , char *num2 ,struct Node *hashArray[] ,  int len){
    int size1 = strlen(num1);
    int size2 = strlen(num2);
    int hashValue = num1[0] - '0' , x = 2;
    for(int i = 1; i<len ; i++){
      hashValue = (hashValue * 2 + num1[i] - '0')%PRIME;
      if(hashValue<0){
        hashValue+=PRIME;
      }
      x = (x * 2)%PRIME;
    }
    InsertatBeg(&hashArray[hashValue] , 0);

    for(int i = 1; i<=size1 -len; i++){
      hashValue = (hashValue * 2 + num1[i + len -1]- '0' - (num1[i-1] - '0') * x)%PRIME;
      if(hashValue<0){
        hashValue = hashValue + PRIME;
      }
      InsertatBeg(&hashArray[hashValue] , i);
    }
     int sub_str_hash = num2[0] - '0', z = 2;
     int j;
     for(j = 1; j<len; j++){
       if(sub_str_hash<0){
        sub_str_hash = sub_str_hash + PRIME;
       }
       sub_str_hash = (sub_str_hash * 2 + num2[j]-'0')%PRIME;
       z = (z * 2)%PRIME;
     }
     struct Node *temp = hashArray[sub_str_hash];
     while(temp!=NULL){
      int u = temp->data;
      int m;
      for(m = 0;u<(temp->data + len); u++ , m++){
           if(num2[m]!=num1[u])
             break;
         }
         if(m==len)
            return 1;
       temp = temp->next;
     }
     for(int k = 1; k<=size2-len; k++){
       sub_str_hash = (sub_str_hash * 2 + num2[k + len -1] - '0' - (num2[k-1] - '0') * z)%PRIME;
       if(sub_str_hash<0){
        sub_str_hash = sub_str_hash + PRIME;
       }

       struct Node *temp = hashArray[sub_str_hash];
       while(temp!=NULL){
         for(int l = k; l<len + k; l++){
           int p = temp->data;
           for(p; p<(temp->data + len); p++){
             if(num2[l]!=num1[p])
               break;
           }
           if(p==(temp->data + len))
             return 1;
         }
         temp = temp->next;
       }
    }
    return 0;
}
int main(){
  char num1[LARGE];
  char num2[LARGE];
  scanf("%s" , num1);
  scanf("%s" , num2);
  int size1 = strlen(num1);
  int min_len = 0, max_len;
  if(strlen(num1) > strlen(num2)){
	  max_len = strlen(num2);
  }else{
	  max_len = strlen(num1);
  }
  int mid = 0;
  while(min_len<=max_len){
    struct Node *hashArray[PRIME] = {NULL};
    mid = (min_len + max_len)/2;

    if(check_substring(num1 , num2 , hashArray , mid)==0){
      max_len = mid  - 1;
    }else{
      min_len = mid + 1;
    }
  }
  printf("%d\n" , min_len-1);
  return 0;
}
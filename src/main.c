// // C Program for Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
struct Contact {
    char name[20];
    char phoneNumber[20];
    struct Contact* next;
};
struct ContactList{
   struct Contact *head;
};

// Function to create a new node 
struct Contact* createNode(char name[20], char phoneNumber[20]) {
    struct Contact* newNode = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phoneNumber);
    newNode->next = NULL;
    return newNode;
}


void add(struct Contact** head,char name[20], char phoneNumber[20]) {
    struct Contact* newNode = createNode(name, phoneNumber);
    if (*head == NULL) {
        *head = newNode;
        printf("Contact %s added\n", name);
        return;
    }
    struct Contact* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Contact %s added\n", name);



}

void update(struct Contact* head,char name[20], char phoneNumber[20]){
    struct Contact* temp = head;
    if(temp == NULL){
        printf("the contact %s does not exist.\n",name);
        return;
    }
    int result;
    while (temp != NULL) {
        result = strcmp(temp->name, name);
        if(result == 0){
            strcpy(temp->phoneNumber, phoneNumber);
            printf("contact %s is updated\n", name);
            return;
        }
        temp = temp->next;
    }        
    printf("the contact %s does not exist.\n",name);
}


void delete(struct Contact* head,char name[20]){
    struct Contact* temp = head;
    if(temp == NULL){
        printf("\nthe contact %s does not exist.\n",name);
        return;
    }
    int result;
    while (temp != NULL) {
        result = strcmp(temp->name, name);
        if(result == 0){
            struct Node* next = temp->next->next;
            free(temp->next);
             temp->next = next;
             printf("\nthe contact %s deleted.\n",name);
             return;

        }
        temp = temp->next;
    }        
    printf("\nthe contact %s does not exist.\n",name);
}
   

void allContacts(struct Contact* head) {
    printf("\nContact List:\n");
    struct Contact* temp = head;
    while (temp != NULL) {
        printf("Contact Name: %s, Phone Number: %s\n", temp->name, temp->phoneNumber);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct ContactList myContacts;
    myContacts.head = NULL;
    add(&myContacts, "Lana", "0600000000");
    add(&myContacts, "Sara", "0607777777");
    add(&myContacts, "Samaa", "0611111111");
    
    allContacts(myContacts.head);
    update(myContacts.head, "Samaa", "0622222222");
    delete(myContacts.head, "Lana");
    allContacts(myContacts.head);
    




}


   

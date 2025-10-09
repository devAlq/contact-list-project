# Contact List Management Project

## Objective
Apply fundamentals of the C programming language to solve real-world problems using arrays and structs.

## Problem
A mobile phone company wants a contact management system that allows users to add, delete, and update contacts.

## Implementation

- Define a `struct Contact` with the following fields:
    - `name`: the contact's name.
    - `phoneNumber`: the contact's phone number.
    - A `pointer` to the next contact in the list.

- Define a `struct ContactList` that manages the contacts as a **linked list**.

- Implement the following functions:
  - `add()`: that adds a new contact to the end of the list and prints a confirmation message.  
  - `delete()`: that deletes a contact by name. If the contact is found, it removes the contact and prints a confirmation message. If not found, it prints a message indicating that the contact does not exist.  
  - `update()`: updates the phone number for the specified name and prints a confirmation message. If the name is not found, it displays a message indicating that the contact does not exist. 
  - `allContacts()`: that displays all the contacts in the list. If the list is empty, it prints a message indicating that no contacts are available.

- In your `main` function:
    - Add 3 contacts to the contact list.
    - Display all contacts.
    - Update the phone number of a contact.
    - Delete one contact.
    - Display all contacts after deletion and update.

## Test Case
```c
int main() {
    ContactList myContacts;
    myContacts.head = NULL;

    add(&myContacts, "Lana", "0600000000");
    add(&myContacts, "Sara", "0607777777");
    add(&myContacts, "Samaa", "0611111111");

    allContacts(&myContacts);

    update(&myContacts, "Samaa", "0622222222");
    delete(&myContacts, "Lana");

    allContacts(&myContacts);

    // Free memory at the end
    Contact* current = myContacts.head;
    while (current != NULL) {
        Contact* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
```
```
Contact Lana added.
Contact Sara added.
Contact Samaa added.

Contact List:
Contact Name: Lana, Phone Number: 0600000000
Contact Name: Sara, Phone Number: 0607777777
Contact Name: Samaa, Phone Number: 0611111111

Contact Samaa updated.

Contact Lana deleted.

Contact List:
Contact Name: Sara, Phone Number: 0607777777
Contact Name: Samaa, Phone Number: 0622222222
```

## Requirements to Pass
- [ ] The code should run successfully.
- [ ] All required functions must be implemented correctly.
- [ ] Completely define the `Contact` struct.
- [ ] Completely define and manage the `ContactList`.

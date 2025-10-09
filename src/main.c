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

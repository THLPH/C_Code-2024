#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;
    struct node *next;
};

// Function prototypes
struct node *find_last(struct node *list, int n);
struct node *insert_at_end(struct node *head, int value);
void print_list(struct node *head);
struct node *delete_last_occurrence(struct node *head, int n);

int main() 
{
    struct node *head = NULL;
    int choice, value, target, count;
    
    // Interactive menu
    do 
    {
        printf("\nMenu:\n");
        printf("1. Add nodes\n");
        printf("2. Print the list\n");
        printf("3. Find last occurrence of a value\n");
        printf("4. Delete last occurrence of a value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("How many values would you like to add? ");
                scanf("%d", &count);
                for (int i = 0; i < count; i++) 
                {
                    printf("Enter value %d: ", i + 1);
                    scanf("%d", &value);
                    head = insert_at_end(head, value);
                }
                break;

            case 2:
                print_list(head);
                break;

            case 3:
                printf("Enter value to find: ");
                scanf("%d", &target);
                struct node *result = find_last(head, target);
                if (result) 
                {
                    printf("Last occurrence of %d found at address: %p\n", target, (void *)result);
                } 
                else 
                {
                    printf("Value %d not found in the list.\n", target);
                }
                break;

            case 4:
                printf("Enter value to delete last occurrence: ");
                scanf("%d", &target);
                head = delete_last_occurrence(head, target);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    // Free memory before exiting
    struct node *temp;
    while (head) 
    {
        temp = head->next;
        free(head);
        head = temp;
    }

    return 0;
}

// Function to insert a node at the end of the list
struct node *insert_at_end(struct node *head, int value) 
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    if (!head) 
    {
        return new_node; // If list is empty, new node becomes the head
    }

    struct node *temp = head;
    while (temp->next) 
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Function to print the linked list
void print_list(struct node *head) 
{
    if (!head) 
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Linked List: ");
    while (temp) 
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to find the last occurrence of a value in the list
struct node *find_last(struct node *list, int n) 
{
    struct node *result = NULL;

    while (list) 
    {
        if (list->value == n) 
        {
            result = list;
        }
        list = list->next;
    }

    return result;
}

// Function to delete the last occurrence of a value
struct node *delete_last_occurrence(struct node *head, int n) 
{
    struct node *temp = head, *prev = NULL, *last = NULL, *last_prev = NULL;

    while (temp) 
    {
        if (temp->value == n) 
        {
            last_prev = prev;
            last = temp;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!last) 
    {
        printf("Value %d not found in the list.\n", n);
        return head;
    }

    if (!last_prev) 
    {
        // The last occurrence is the head node
        head = head->next;
    } 
    else 
    {
        last_prev->next = last->next;
    }

    free(last);
    printf("Last occurrence of %d deleted.\n", n);
    return head;
}

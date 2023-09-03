#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode *next;
};

#define LIST_NODE_SIZE sizeof(struct ListNode)
#define CREATE_NODE (struct ListNode *) malloc(LIST_NODE_SIZE)

void add(struct ListNode **head);
void delete(struct ListNode **head);
void search(struct ListNode **head);
void print_list(struct ListNode *head);

void add(struct ListNode **head) {
    struct ListNode *current = NULL;
    struct ListNode *next = NULL;
    struct ListNode *new_node = NULL;

    int value = 0;

    printf("Ingresa el valor a insertar: ");
    scanf(" %d", &value);

    new_node = CREATE_NODE;
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        next = current->next;

        while (next != NULL) {
            current = next;
            next = current->next;
        }

        current->next = new_node;
    }
}

void delete (struct ListNode **head) {
    struct ListNode *current = NULL;
    struct ListNode *next = NULL;
    struct ListNode *previous = NULL;

    int value = 0;

    printf("Ingresa el valor a borrar: ");
    scanf(" %d", &value);

    current = *head;
    next = current->next;

    while (current != NULL) {
        if (current->value == value) {
            if (previous == NULL) {
                *head = next;
            } else {
                previous->next = next;
            }

            free(current);
            break;
        }

        previous = current;
        current = next;
        next = current->next;
    }
}

void search(struct ListNode **head) {
    struct ListNode *current = NULL;
    struct ListNode *next = NULL;

    int value = 0;

    printf("Ingresa el valor a buscar: ");
    scanf(" %d", &value);

    current = *head;
    next = current->next;

    while (current != NULL) {
        if (current->value == value) {
            printf("El valor %d existe en la lista\n", value);
            break;
        }

        current = next;
        next = current->next;
    }

    if (current == NULL) {
        printf("El valor %d no existe en la lista\n", value);
    }
}

void print_list(struct ListNode *head) {
    if (head == NULL) {
        printf("La lista esta vacia\n");
        return;
    }

    while (head != NULL) {
        printf("Numero: %d\n", head->value);
        head = head->next;
    }
}

int main(void) {
    struct ListNode *head = NULL;

    int option = 0;

    while (option != 5) {
        printf("\t1. Adicionar dato\n");
        printf("\t2. Borrar dato\n");
        printf("\t3. Buscar dato\n");
        printf("\t4. Imprimir lista\n");
        printf("\t5. Salir\n");
        printf("Ingresa una opcion:");
        scanf(" %d", &option);

        switch (option) {
            case 1:
                add(&head);
                continue;
            case 2:
                delete(&head);
                continue;
            case 3:
                search(&head);
                continue;
            case 4:
                print_list(head);
                continue;
            case 5:
                printf("Adios!\n");
                continue;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }

    return 0;
}

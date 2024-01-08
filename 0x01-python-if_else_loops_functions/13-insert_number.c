#!/usr/bin/python3
#include <list.h>
#include <stdlib.h>

typedef struct listint_s {
   int n;
   struct listint_s *next;
} listint_t;

listint_t *insert_node(listint_t **head, int number) {
   listint_t *new_node = malloc(sizeof(listint_t));
   if (new_node == NULL) {
       return NULL;  // Memory allocation failed
   }

   new_node->n = number;
   new_node->next = NULL;

   // Handle empty list or insertion at the beginning
   if (*head == NULL || (*head)->n >= number) {
       new_node->next = *head;
       *head = new_node;
       return new_node;
   }

   // Find the appropriate position for insertion
   listint_t *current = *head;
   while (current->next != NULL && current->next->n < number) {
       current = current->next;
   }

   new_node->next = current->next;
   current->next = new_node;

   return new_node;
}

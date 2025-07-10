/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nistanoj <nistanoj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:26:22 by nistanoj          #+#    #+#             */
/*   Updated: 2025/07/09 14:28:52 by nistanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "../push_swap.h"  // Ajustez le chemin si nécessaire

// Vérifie si la pile est triée en ordre croissant
static bool is_sorted(const t_stack *stack) {
    if (stack->size < 2)
        return true;
    t_node *cur = stack->top;
    while (cur->next) {
        if (cur->value > cur->next->value)
            return false;
        cur = cur->next;
    }
    return true;
}

// Exécute un test et affiche le résultat
static void test_case(int arr[], int len, const char *name) {
    t_stack a;
    stack_init(&a);
    // Remplir la pile
    for (int i = 0; i < len; i++)
        stack_push(&a, arr[i]);

    // Appliquer la fonction à tester
    sort_small(&a);

    // Vérification
    if (is_sorted(&a))
        printf("[OK] %s\n", name);
    else {
        printf("[FAIL] %s ->", name);
        for (t_node *n = a.top; n; n = n->next)
            printf(" %d", n->value);
        printf("\n");
    }

    // Libération de la pile
    while (a.size > 0)
        stack_pop(&a);
}

int main(void) {
    printf("=== Test sort_small() ===\n");

    // Cas taille 2
    int a2[] = {1, 2};
    test_case(a2, 2, "[1,2]");
    int b2[] = {2, 1};
    test_case(b2, 2, "[2,1]");

    // Permutations taille 3
    int perms3[6][3] = {
        {1, 2, 3}, {1, 3, 2},
        {2, 1, 3}, {2, 3, 1},
        {3, 1, 2}, {3, 2, 1}
    };
    for (int i = 0; i < 6; i++) {
        char name[16];
        snprintf(name, sizeof(name), "[%d,%d,%d]", perms3[i][0], perms3[i][1], perms3[i][2]);
        test_case(perms3[i], 3, name);
    }

    return 0;
}

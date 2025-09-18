import heapq # Importa a biblioteca heapq para usar uma fila de prioridade

grafo1 = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D':  5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}
'''
A--1-B--5-D
 \   |   /
  4  2  1
   \ | /
     C
'''



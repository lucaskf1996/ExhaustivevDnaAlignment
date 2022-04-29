# Algoritmo para alinhamento de sequências de DNA exaustiva
Sendo i o índice do início da substring A, j o índice do início da substring B, k o tamanho das substrings, n o tamanho da sequência A, m o tamanho da sequência B, subA a substring A e subB a substring B, utiliza-se o pseudo-código abaixo para fazer os alinhamentos:

1. k = tamanho da menor sequência
2. Enquanto k >= 2 e k > tamanho mínimo de substring que pode atingir o maior score:
    3. Enquanto i < n-k:
        4. subA = substring de tamanho k a partir do indice i
        5. Enquanto j < m-k:
            6. subB = substring de tamanho k a partir do indice i
            7. Calcular score entre subA e subB

O código no estado atual não percorre todas as possibilidades como um algoritmo exaustivo. Isso ocorre, pois foram efetuadas algumas modificações. A primeira verifica substrings repetidas, ou seja, para cada tamanho k, as substrings verificadas para cada sequência são armazenadas para comparação com as novas substrings geradas. Caso uma esteja previamente armazenada, os loops subsequentes não serão efetuados. Além disso, a partir do score máximo, é calculado o tamanho de string mínimo para que seja possível atingir um score igual ou maior, ou seja, como o valor para um match é de 2 pontos, caso o score máximo em certo ponto do algoritmo seja 16, então o tamanho mínimo será 8.
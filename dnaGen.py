import random
n = 10000 # tamanho da primeira sequência
m = 100 # tamanho da segunda sequência
file = 'dna.seq' # nome do arquivo a ser gerado
f = open(file, 'w')
seq=[str(n)+'\n',
     str(m)+'\n',
     ''.join(random.choices(['A','T','C','G','-'],k=n))+'\n',
     ''.join(random.choices(['A','T','C','G','-'],k=m))]
f.writelines(seq)
f.close()
print(''.join(seq))

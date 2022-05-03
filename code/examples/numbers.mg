// Preencher um arranjo com numeros lidos do teclado.
def arr = []
def n
while (n != 0) {
  n = read('Entre com um numero inteiro (0 para sair): ') as Integer
  if (n != 0)
    arr += [n]
}

// Separar os numeros em positivos e negativos.
def map = [:]
for (def (i, e) = [0, size(arr)]; i < e; i += 1) {
  def tmp = arr[i]
  if (tmp < 0) {
    if (!map.neg)
      map.neg = []

    map.neg += [tmp]
  } else {
    if (!map.pos)
      map.pos = []

    map.pos += [tmp]
  }
}

// Imprimir os numeros separadamente.
println('')
foreach (def k in keys(map)) {
  def name = switch (k) {
    case 'pos' -> 'Positivos'
    case 'neg' -> 'Negativos'
  }

  println(name + ': ' + map[k])
}

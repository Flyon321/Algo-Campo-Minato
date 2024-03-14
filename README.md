<h1>Specifiche del Problema</h1>
Ci sono N mine in un vecchio campo di battaglia. Ogni mina colpisce un'area quadrata parallela all'asse, a seconda delle sue prestazioni. Si supponga che la posizione della mina sia il centro dell'area quadrata. Quando una mina esplode, esploderanno anche tutte le mine presenti nell'area quadrata dell'esplosione. Come una reazione a catena, tutte le mine nell'area quadrata dell'esplosione successiva esploderanno anch'esse. Supponiamo che quando una mina sta esplodendo, una mina che si trova sul bordo dell'area quadrata dell'esplosione esploderà anch'essa.
 Il programma deve leggere l'input da standard input. L'input è costituito da T test case. Il numero di test case T è indicato nella prima riga dell'input. Ogni test case inizia con una riga contenente un intero N (3 ≤ N ≤ 2.000), che rappresenta il numero di mine. Nelle successive N righe, ogni riga contiene tre numeri interi x, y e d, dove x e y sono le coordinate della mina nel piano e d è la dimensione di un lato del quadrato, che rappresenta l’estensione dell'esplosione (1 ≤ x, y ≤ 10000000, 1 ≤ d ≤ 1000000).
<h1>Obiettivo</h1>
Il codice risolve un problema di esplorazione di una griglia di mine al fine di determinare il numero minimo di mine che devono essere fatte esplodere affinché non ci siano mine rimaste intatte.
<h1>Rappresentazione</h1>
Una possibile rappresentazione sfrutta l’uso di un grafo orientato.
Le mine rappresentano i nodi del grafo diretto e gli archi sono rappresentati dalla copertura nel piano cartesiano di altre mine. Se una mina A copre con la sua area d’esplosione un’ipotetica mina B, vorrà dire che la mina A punterà alla mina B.

<h1>Correttezza e Complessità</h1>
Questo algoritmo consente di calcolare il minor numero di mine da far esplodere per far esplodere tutte le mine nel campo grazie alla costruzione di una lista di adiacenza che viene fatta nella funzione buildGraph(), e sfrutta la visita in profondità (DFS) che trova tutte le componenti connesse di un grafo usando implicitamente uno stack; All'inizio della chiamata alla funzione dfs, il nodo corrente viene segnato come visitato impostando visited[node] = true. 
Per ogni nodo adiacente al nodo corrente nel grafo:
•	Se il nodo adiacente non è stato ancora visitato, viene chiamata ricorsivamente la funzione dfs passando il nodo adiacente come nuovo nodo di partenza.
•	Questo passo continua fino a quando non vengono visitati tutti i nodi raggiungibili dal nodo di partenza.
La complessità temporale della funzione dfs dipende dal numero di nodi e archi nel grafo. In generale, la DFS ha una complessità temporale di O(|V| + |E|), dove V è il numero di nodi (mine) e E è il numero di archi (connessioni tra le mine) nel grafo.
Quindi:
Ordinare la lista delle adiacenze: O(n log n) Tramite quicksort
DFS: O(|V| + |E|)

![OUTPUT 2](https://github.com/Flyon321/Algo-Campo-Minato/assets/76116045/11079ec8-708e-480b-b5e1-f452273af124)
Questa rappresentazione da in output 2

![OUTPUT 7](https://github.com/Flyon321/Algo-Campo-Minato/assets/76116045/5ce5ea04-58da-4223-b069-a846e0a76f7b)
Questa rappresentazione da in output 7

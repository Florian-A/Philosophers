<h1 align="center">Philosopher</h1>

Neuvieme projet de [42](https://42.fr/) qui a pour but d'apprendre le comportement des threads en C.

L'objectif est d'implémenter une des solutions du [Diner des philosophes](https://fr.wikipedia.org/wiki/D%C3%AEner_des_philosophes) en utilisant les concepts suivants :

- Gestion de ressources partagées
- Gestion des problèmatiques de temps d'execution

---

### Compilation :

Pour compiler le projet, exécutez la commande suivante :

```
make
```

Pour compiler les tests unitaires, exécutez la commande suivante :

```
make test
```

### Utilisation :

Pour lancer le programme, `./philosopher` `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `[number_of_times_each_philosopher_must_eat]`

Exemple :

```
./philo 4 210 100 100 3
```

Les tests unitaires s'executent de la façon suivante :

```
./utest
```

### Démonstration :

<img src="./img/video1.gif" />

### Intégration continue :

[![norminette](https://github.com/Florian-A/Philosopher/actions/workflows/norm.yml/badge.svg)](https://github.com/Florian-A/Philosopher/actions/workflows/norm.yml) [![unit test + build](https://github.com/Florian-A/Minishell/actions/workflows/utest+build.yml/badge.svg)](https://github.com/Florian-A/Minishell/actions/workflows/utest+build.yml)

### Correction :

| |
| --- |
| <img src="./img/note.png" style="zoom: 50%;" /> |

| | |
| --- | --- |
| Correcteur 1 | <img src="./img/correction1.png" style="zoom: 67%;" /> |
| Correcteur 2 | <img src="./img/correction2.png" style="zoom:67%;" /> |
| Correcteur 3 | <img src="./img/correction3.png" style="zoom:67%;" /> |

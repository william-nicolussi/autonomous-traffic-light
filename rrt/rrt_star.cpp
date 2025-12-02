/* ----- RRT* ALGORITHM ----- */

#include "rrt_support.h"
#include <vector>

void rrt_star(node start, node goal, obstacle obs0, obstacle obs1, obstacle obs2, std::vector<node> &path_car)
{
    /*
    int num_node = 0;

    // Definisco un vettore di nodi che verrà aggiornato dall'algoritmo RRT*
    std::vector<node> nodevec;

    // Definisco un vettore che conterrà i parent dei nodi, avendo corrispondenza tra gli indici con il vettore dei nodi
    std::vector<node> nodevec_par;

    // Definisco il vettore con i punti del path finale
    std::vector<node> path;

    // Aggiungo il punto di partenza al vettore
    nodevec.push_back(start);
    nodevec_par.push_back(start);
    num_node++;

    srand(time(NULL));

    // INIZIO ALGORITMO RRT*

    while (1)
    {
        // printf("node %d\n", num_node);
        if (num_node > 30000)
        {
            printf("Path not find :(\n");
            break;
        }

        // Prendo un punto random
        node random;
        random.p.x = rand() % 1800; // Lunghezza strada * 10
        random.p.y = rand() % 40;   // Larghezza strada * 10

        // Prendo il punto dell'albero più vicino a quello random
        int index = closest_node(num_node, nodevec, random);
        node closest = nodevec[index];

        // Estendo il ramo nella direzione del punto random
        node extended = extend(random, closest);

        // Individuo la retta tra i due punti e genero un vettore per verificare se la retta interseca punti che sono ostacoli
        double interval = 0.1;
        int point_retta = (int)(abs(extended.p.x - closest.p.x) / interval) + 1;
        std::vector<double> rvecx;
        std::vector<double> rvecy;
        double m, b;
        m = retta(extended, closest, rvecx, rvecy, point_retta, m, b);
        int isobs = isObstacle(rvecx, rvecy, obs0, obs1, obs2, point_retta, extended);

        // Aggiungo un nuovo punto all'albero se non incontra ostacoli
        if (isobs != 1 && m <= 1)
        {
            nodevec.push_back(extended);    // aggiungo nodo all'albero
            nodevec_par.push_back(closest); // aggiungo il parent del nodo

            // Termina algoritmo quando un punto dell'albero è a distanza d <= min_distance dal punto finale
            double d = getDistance(nodevec[num_node], goal);

            if (d <= min_distance)
            {
                printf("Punto finale = (%f, %f)\n", extended.p.x, extended.p.y);
                printf("Percorso trovato!\n");

                // Calcolo costo del percorso
                double cost = path_cost(nodevec, nodevec_par, num_node, path);
                int tot_nodes = (int)path.size();
                printf("Costo = %f\n", cost);
                printf("nodes = %d\n", tot_nodes);

                for (int i = 1; i <= tot_nodes; i++)
                {
                    path_car.push_back(path[tot_nodes - i]);
                    path_car[i - 1].p.x = (path_car[i - 1].p.x) / 10.0;
                    path_car[i - 1].p.y = (path_car[i - 1].p.y) / 10.0;
                }

                FILE *file = fopen("path.txt", "w");

                fprintf(file, "Path found!\n");
                fprintf(file, "Starting point = (%f, %f)\n", nodevec[0].p.x / 10.0, nodevec[0].p.y / 10.0);
                fprintf(file, "Final point = (%f, %f)\n", nodevec[num_node].p.x / 10.0, nodevec[num_node].p.y / 10.0);
                fprintf(file, "Cost = %f\n", cost);
                fprintf(file, "nodes = %d\n", tot_nodes);

                for (int i = 0; i < tot_nodes; i++)
                {
                    fprintf(file, "(%f, %f)\n", path_car[i].p.x, path_car[i].p.y);
                }

                fclose(file);

                break;
            }

            num_node++;
        }
    }*/
}
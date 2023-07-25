#include "PmergeMe.hpp"
unsigned int tmp;
bool pair = true;

template <typename C1, typename C2, typename C3>


void    algo(int ac, char container, C1 &container1, C2 &container2, C3 &container3) // do the john algo
{
    // struct timeval start, end;
    // long sec, micro;

    // gettimeofday(&start, NULL);
    (void) container;
    std::cout << ac << std::endl;
    for (size_t i = 0; i < container1.size(); i++) // mettre les nombres en duo et swap si c pas trié
    {
        if (container1[i].first > container1[i].second)
            std::swap(container1[i].first, container1[i].second);
    }

    for (size_t i = 0; i < container1.size(); i++)// push tout les premiers argu dans un containers et en trier un de mon choix
        container2.push_back(container1[i].first);    
        
    for (size_t i = 0; i < container1.size(); i++) // push tout les derniers argu dans un containers et en trier un de mon choix
        container3.push_back(container1[i].second);

    std::sort(container2.begin(), container2.end()); // trier un container après on va mettre les nombres du second non trié au compte goutte via lower bound

    for (size_t i = 0; container3.size(); i++)
        container2.insert(std::lower_bound(container2.begin(), container2.end(), container3[i]), container3[i]);
    
    if (pair == false)
        container2.insert(std::lower_bound(container2.begin(), container2.end(), tmp), tmp);
    
    std::cout << "\nAfter : ";

    for (size_t i = 0; i < container2.size(); i++)
    {
        std::cout << container2[i] << " ";
    }

    // gettimeofday(&end, NULL);
    // sec = end.tv_sec - start.tv_sec;
    // micro = end.tv_usec - start.tv_usec;
    // long diff = (sec / 1000000) + (micro);
    // if (container == 'v')
    //     std::cout << "\nTime to process a range of " << ac << " elements with std::vector : " << diff  << " us" << "\n";
    // if (container == 'd')
    //     std::cout << "\nTime to process a range of " << ac << " elements with std::deque : " << diff  << " us" << "\n";
}
int main(int ac, char **av)
{

    for (int i = 1; i < ac; i++)
    {
        tmp = std::atoi(av[i]);
        if (std::atoi(av[i]) < 0)
        {
            std::cout << "Found an negative number" << std::endl; //throw an error
            exit(1);
        }
        else if (!isdigit(*av[i]))
        {
            std::cout << "Error, not a number" << std::endl; //throw an error
            exit(1);
        }
    }

    if ((ac - 1) % 2 != 0)
    {
        pair = false;
        ac-=1; // ? jai pas compris l'utiliter on verra
    }

    std::cout << "Before : ";

    if (ac < 6)
    {
        for (int i = 1; i < ac; i++)
            std::cout << av[i] << " ";
    }
    else
    {
        for (int i = 1; i < 6; i++)
            std::cout << av[i] << " ";
        std::cout << "[...]";      
    }

    // Vector

    std::vector<std::pair<unsigned int, unsigned int> > vector1;

    for (int i = 1; i < ac; i += 2)
    {
        if (isdigit(*av[i]))
            vector1.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
    }
    std::vector<unsigned int> vector2, vector3;
    algo(ac, 'v', vector1, vector2, vector3);

    //Deque

    std::deque<std::pair<unsigned int, unsigned int> > deque1;
    for (int i = 1; i < ac; i+=2)
    {
        if (isdigit(*av[i]))  
            deque1.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));

    }
    std::deque<unsigned int> deque2, deque3;
    algo(ac, 'd', deque1, deque2, deque3);
}
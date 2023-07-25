#include "PmergeMe.hpp"
unsigned int tmp;
bool pair = true;


bool isdigit1(char *str) {
    if (str == NULL)
        return false;
    while (*str) {
        if (!std::isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

template <typename C1, typename C2, typename C3>

void    algo(int ac, char container, C1 &container1, C2 &container2, C3 &container3) // john algo
{
    struct timeval start, end;
    long sec, micro;

    gettimeofday(&start, NULL);
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

    for (size_t i = 0; i < container3.size(); i++)
        container2.insert(std::lower_bound(container2.begin(), container2.end(), container3[i]), container3[i]);
    
    if (pair == false)
        container2.insert(std::lower_bound(container2.begin(), container2.end(), tmp), tmp);
    
    std::cout << "\nAfter: ";
    for (size_t i = 0; i < container2.size(); i++)
    {
        std::cout << container2[i] << " ";
    }

    gettimeofday(&end, NULL);
    sec = end.tv_sec - start.tv_sec;
    micro = end.tv_usec - start.tv_usec;
    long diff = (sec / 1000000) + (micro);
    if (pair == true)
        ac -= 1;
    if (container == 'v')
        std::cout << "\nTime to process a range of " << ac << " elements with std::vector : " << diff  << " us" << "\n";
    if (container == 'd')
        std::cout << "\nTime to process a range of " << ac << " elements with std::deque : " << diff  << " us" << "\n";
}
int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::runtime_error("No arguments");
        for (int i = 1; i < ac; i++)
        {
            if (std::atoi(av[i]) < 0)
                throw std::runtime_error("Found an negative number");
            if (!isdigit1(av[i]))
                throw std::runtime_error("Error, not a number");
            tmp = std::atoi(av[i]);
        }
        if ((ac - 1) % 2 != 0)
        {
            ac -= 1;
            pair = false;
        }

        std::cout << "Before: ";
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
            vector1.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
        std::vector<unsigned int> vector2, vector3;
        algo(ac, 'v', vector1, vector2, vector3);

        //Deque
        std::deque<std::pair<unsigned int, unsigned int> > deque1;
        for (int i = 1; i < ac; i += 2) 
                deque1.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
        std::deque<unsigned int> deque2, deque3;
        algo(ac, 'd', deque1, deque2, deque3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
}
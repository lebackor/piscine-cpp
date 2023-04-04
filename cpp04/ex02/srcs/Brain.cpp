#include "../includes/Brain.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

	std::string _rawideas[100] = {
        "I think, therefore I am.",
        "What is the meaning of life?",
        "To be or not to be, that is the question.",
        "The only true wisdom is in knowing you know nothing.",
        "It does not matter how slowly you go as long as you do not stop.",
        "I have not failed. I've just found 10,000 ways that won't work.",
        "All that we see or seem is but a dream within a dream.",
        "You miss 100 of the shots you don't take.",
        "In the end, we will remember not the words of our enemies, but the silence of our friends.",
        "Believe you can and you're halfway there.",
        "Success is not final, failure is not fatal: It is the courage to continue that counts.",
        "Happiness is not something ready made. It comes from your own actions.",
        "The journey of a thousand miles begins with one step.",
        "Education is the most powerful weapon which you can use to change the world.",
        "A day without laughter is a day wasted.",
        "If you want to go fast, go alone. If you want to go far, go together.",
        "You can't blame gravity for falling in love.",
        "Do not go where the path may lead, go instead where there is no path and leave a trail.",
        "The best way to predict your future is to create it.",
        "The only way to do great work is to love what you do.",
        "If you're going through hell, keep going.",
        "Our greatest weakness lies in giving up. The most certain way to succeed is always to try just one more time.",
        "You must be the change you wish to see in the world.",
        "Life is like a camera. Focus on the good times, develop from the negatives, and if things don't work out, take another shot.",
        "The most common way people give up their power is by thinking they don't have any.",
        "You are never too old to set another goal or to dream a new dream.",
        "A true hero isn't measured by the size of his strength, but by the strength of his heart.",
        "Don't count the days, make the days count.",
        "The best preparation for tomorrow is doing your best today.",
        "It always seems impossible until it's done.",
        "If you want to live a happy life, tie it to a goal, not to people or things.",
        "Happiness is not something you postpone for the future; it is something you design for the present.",
        "It is never too late to be what you might have been.",
        "In three words I can sum up everything I've learned about life: it goes on.",
        "Life is 10% what happens to you and 90 how you react to it.",
        "Success is stumbling from failure to failure with no loss of enthusiasm.",
        "You can't go back and change the beginning, but you can start where you are and change the ending.",
        "The pessimist sees difficulty in every opportunity. The optimist sees opportunity in every difficulty.",
        "Be the change that you wish to see in the world.",
        "A person who never made a mistake never tried anything new.",
        "Everything you've ever wanted is on the other side of fear.",
        "Believe in yourself and all that you are.",
		"Know that there is something inside you that is greater than any obstacle.",
		"The only limit to our realization of tomorrow will be our doubts of today.",
		"We may encounter many defeats but we must not be defeated.",
		"Success is not how high you have climbed, but how you make a positive difference to the world.",
		"Change your thoughts and you change your world.",
		"What you get by achieving your goals is not as important as what you become by achieving your goals.",
		"The only person you are destined to become is the person you decide to be.",
		"The only way to have a good day is to start it with a positive attitude.",
		"You can't connect the dots looking forward; you can only connect them looking backwards. So you have to trust that the dots will somehow connect in your future.",
		"If you're not making mistakes, then you're not making decisions.",
		"A person who never made a mistake never tried anything new.",
		"It's not the years in your life that count. It's the life in your years.",
		"It is during our darkest moments that we must focus to see the light.",
		"I can't change the direction of the wind, but I can adjust my sails to always reach my destination.",
		"The future belongs to those who believe in the beauty of their dreams.",
		"The biggest risk is not taking any risk.",
		"I would rather die of passion than of boredom.",
		"Believe in yourself, take on your challenges, dig deep within yourself to conquer fears. Never let anyone bring you down. You got this.",
		"A man who stands for nothing will fall for anything.",
		"In the midst of chaos, there is also opportunity.",
		"If you want to change the world, change yourself.",
		"Believe you can and you're halfway there.",
		"The only way to have a good day is to start it with a positive attitude.",
		"It's not whether you get knocked down, it's whether you get up.",
		"The secret of change is to focus all of your energy, not on fighting the old, but on building the new.",
		"A goal without a plan is just a wish.",
		"The only thing necessary for the triumph of evil is for good men to do nothing.",
		"You are the master of your fate, the captain of your soul.",
		"You have brains in your head. You have feet in your shoes. You can steer yourself any direction you choose.",
		"The only true way to success is to never give up on your dreams.",
		"It's not about how hard you can hit, it's about how hard you can get hit and keep moving forward.",
		"The best and most beautiful things in the world cannot be seen or even touched - they must be felt with the heart.",
		"Believe in the power of your dreams.",
		"Dream big, work hard, stay focused, and surround yourself with good people.",
		"If you don't stand for something, you will fall for anything.",
		"The only limit to our realization of tomorrow will be our doubts of today.",
		"Believe you can and you're halfway there.",
		"The only way to do great work is to love what you do.",
		"Don't wait for opportunities, create them.",
		"In order to be irreplaceable, one must always be different.",
		"Never give up on what you really want to do. The person with big dreams is more powerful than the one with all the facts.",
		"The greatest glory in living lies not in never falling, but in rising every time we fall.",
		"You must be the change you wish to see",
		"Don't let yesterday take up too much of today.",
		"The two most important days in your life are the day you are born and the day you find out why.",
		"Success is not final, failure is not fatal: it is the courage to continue that counts.",
		"The true test of character is not how much we know how to do, but how we behave when we don't know what to do.",
		"Your time is limited, don't waste it living someone else's life.",
		"You can't build a reputation on what you are going to do.",
		"Happiness is not something you postpone for the future; it is something you design for the present.",
		"Imagination is more important than knowledge.",
		"Chase your dreams but always know the road that will lead you home again.",
		"When you have a dream, you've got to grab it and never let go.",
		"The best way to predict the future is to invent it.",
		"Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.",
		"The difference between ordinary and extraordinary is that little extra.",
		"A day without laughter is a day wasted.",
		"The only way to do great work is to love what you do.",};

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = _rawideas[rand() % (sizeof(_rawideas) / sizeof(std::string))];
	std::cout << BOLDBLUE << "Created a brain !" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Destroyed a brain !" << RESET << std::endl;
}

const std::string& Brain::getIdeas(int index) const
{
	return (this->_ideas[index]);
}

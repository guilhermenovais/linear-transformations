#ifndef VETOR_HPP
#define VETOR_HPP

class Vetor {
	private:
		unsigned long int x, y;
	public:
		Vetor(unsigned long int newX, unsigned long int newY);
		unsigned long int getX();
		unsigned long int getY();
		void setX(unsigned long int newX);
		void setY(unsigned long int newY);
};

#endif // VETOR_HPP

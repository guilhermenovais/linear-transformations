#ifndef VETOR_HPP
#define VETOR_HPP

class Vetor {
	private:
		unsigned int x, y;
	public:
		Vetor(unsigned int newX, unsigned int newY);
		unsigned int getX();
		unsigned int getY();
		void setX(unsigned int newX);
		void setY(unsigned int newY);
};

#endif // VETOR_HPP

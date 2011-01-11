#ifndef SKIMAN_H_INCLUDED
#define SKIMAN_H_INCLUDED

class Skiman
{
	public :
		Skiman(float px, float py, float pz);
		~Skiman();
		void draw();
	protected:
		float x;
		float y;
		float z;
}

#endif
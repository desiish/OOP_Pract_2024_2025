#include <iostream>
#include <fstream>

constexpr size_t MAX_RELATION_SIZE = 25;

struct Pair {
	int x, y;
};

struct Relation {
	Pair pairs[MAX_RELATION_SIZE] = {};
	int currentSize = 0;
};

void readPairFromFile(std::ifstream& ifs, Pair& p)
{
	ifs >> p.x;
	if (!ifs.good()) {
		std::cerr << "Error while reading pair!";
		return;
	}

	ifs >> p.y;
	if (!ifs.good()) {
		std::cerr << "Error while reading pair!";
		return;
	}
}

void readRelationFromFile(std::ifstream& ifs, Relation& relation)
{
	ifs >> relation.currentSize;

	if (relation.currentSize < MAX_RELATION_SIZE) {

		for (int i = 0; i < relation.currentSize; i++)
		{
			readPairFromFile(ifs, relation.pairs[i]);
		}
	}
	else {
		std::cerr << "U exceed the relation limit!";
		return;
	}
}

void addPairToRelation(const Pair& pair, Relation& relation)
{
	if (relation.currentSize <= MAX_RELATION_SIZE)
	{
		relation.pairs[relation.currentSize].x = pair.x;
		relation.pairs[relation.currentSize].y = pair.y;

		relation.currentSize++;
	}
	else {
		std::cerr << "Relation limit!";
		return;
	}
}

void writePairToFile(std::ofstream& ofs, const Pair& pair)
{
	ofs << "<" << pair.x << "," << pair.y << ">" << "\n";
}

void writeRelationToFile(std::ofstream& ofs, const Relation& relation)
{
	for (int i = 0; i < relation.currentSize; i++)
	{
		writePairToFile(ofs, relation.pairs[i]);
	}
}

int main()
{
	std::ifstream ifs("relations.txt");
	if (!ifs.is_open())
	{
		std::cerr << "Error while opening the file for reading";
		return;
	}

	std::ofstream ofs("file.txt");
	if (!ofs.is_open())
	{
		std::cerr << "Error while opening the file for writing";
		return;
	}

	ifs.close();
	ofs.close();
}

#include <iostream>
#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CLEAR "\033[0m"

int	main() {
	{
		std::cout << "➡️  Composition part\n" << std::endl;

		std::cout << RED;
		std::cout << "Creation of workers by default constructor and with values" << std::endl;
		Worker	jean;

		std::cout << jean << std::endl;

		Worker	paul(18, 458, 17, 4570);

		std::cout << paul << std::endl;

		std::cout << "First worker is moving to join the second one !" << std::endl;
		jean.setPosition(18, 54, 15);

		std::cout << "\nHe found some gems on the road and earned exps !\n" << std::endl;
		jean.earnExp(1020);

		std::cout << jean << std::endl;
	}

	std::cout << CLEAR;
	std::cout << "\n----------------------------------------\n" << std::endl;
	std::cout << std::boolalpha;

	{
		std::cout << "➡️  Aggregation\n" << std::endl;

		std::cout << BLUE;
		Worker	jacques(428, 872, 480, 34060);

		std::cout << jacques << std::endl;

		std::cout << "Let's create a shovel and give it to our worker" << std::endl;
		Shovel	shovel;

		jacques.takeTool(shovel);
		std::cout << "\nIs worker have shovel ? " << jacques.isWorkerHaveTool(shovel) << '\n' << std::endl;

		std::cout << "Let's create a second worker who will stole the shovel of the first one" << std::endl;
		Worker*	chirac = new Worker(427, 872, 480, 24990);

		chirac->takeTool(shovel);
		std::cout << "\nIs first worker have shovel ? " << jacques.isWorkerHaveTool(shovel) << std::endl;
		std::cout << "Is second worker have shovel ? " << chirac->isWorkerHaveTool(shovel) << '\n' << std::endl;

		std::cout << "Second worker has done working, first one needs the shovel" << std::endl;
		delete chirac;
		jacques.takeTool(shovel);

		std::cout << "\nIs worker have shovel ? " << jacques.isWorkerHaveTool(shovel) << '\n' << std::endl;
	}

	std::cout << CLEAR;
	std::cout << "\n----------------------------------------\n" << std::endl;

	{
		std::cout << "➡️  Inherence part\n" << std::endl;

		std::cout << RED;
		std::cout << "Create a worker" << std::endl;
		Worker	blume(100, 100, 100, 10500);

		std::cout << blume << std::endl;

		std::cout << "Let's give to worker a shovel and a hammer\n" << std::endl;

		Shovel	shovel;
		Hammer	hammer;

		blume.takeTool(shovel);
		blume.takeTool(hammer);

		std::cout << "\nIs worker have shovel ? " << blume.isWorkerHaveTool(shovel) << std::endl;
		std::cout << "Is worker have hammer ? " << blume.isWorkerHaveTool(hammer) << '\n' << std::endl;

		std::cout << "Create a second worker that'll take the hammer of the first one" << std::endl;

		Worker	meblu(101, 100, 100, 87900);

		meblu.takeTool(hammer);

		std::cout << "\nIs first worker have hammer ? " << blume.isWorkerHaveTool(hammer) << std::endl;
		std::cout << "Is second worker have hammer ? " << meblu.isWorkerHaveTool(hammer) << '\n' << std::endl;
	}

	std::cout << CLEAR;
	std::cout << "\n----------------------------------------\n" << std::endl;

	{
		std::cout << "➡️  Association part\n" << std::endl;

		std::cout << BLUE;
		std::cout << "Create some workers" << std::endl;
		Worker	toto(254, 118, -42, 54080);
		Worker	titi(100, 240, -12, 43980);
		Worker	tutu(764, 238, 250, 108756);

		std::cout << toto << std::endl;
		std::cout << titi << std::endl;
		std::cout << tutu << std::endl;

		std::cout << "Create three workshops" << std::endl;

		Workshop	workshopUnn;
		Workshop	workshopA("A");
		Workshop	workshopB("B");

		std::cout << "\nAssign to all worker a workshop with the workshop and by themselves\n" << std::endl;

		toto.registerToWorkshop(workshopUnn);
		workshopA.registerWorker(&titi);
		tutu.registerToWorkshop(workshopB);

		std::cout << "\nWorkers wants to work at workshopA" << std::endl;

		toto.work(workshopA);
		titi.work(workshopA);

		std::cout << "\nFirst workshop forgot to register to workshopA" << std::endl;

		toto.registerToWorkshop(workshopA);

		std::cout << "\nWorkshopA is not happy of the work that has been done, they want to start a day of working" << std::endl;

		workshopA.executeWorkDay();

		std::cout << "\nWorkshopA is not happy of his workers, let's fired them" << std::endl;

		workshopA.releaseWorker(&toto);
		workshopA.releaseWorker(&titi);

		std::cout << "\nLet's try to work to check if they are really released" << std::endl;

		workshopA.executeWorkDay();
		toto.work(workshopA);
		titi.work(workshopA);

		std::cout << "\nWorkshopA want to try with the third worker" << std::endl;

		workshopA.registerWorker(&tutu);
		workshopA.executeWorkDay();

		std::cout << std::endl;
	}
	return 0;
}

class Container{

    int number; //registration number
    double tareWeight; //own weight of an empty container
    double maxWeight; //maximum container weight with a load
    double strength; //maximum external weight of other containers placed upon this one
    double cargo; //weight of the load in the container (cargo=netWeight)

    public:

        Container();
        //Container(int, double, double, double, double);
        Container(int);

        int getNumber();

        double getTare();

        void setTare(double tareWeight);

        double getMaxWeight();

        void setMaxWeight(double maxWeight);

        double getStrength();

        void setStrength(double strength);

        double getGrossWeight();

        double getNetWeight();

        double getMaxCargo();

        void loadCargo(double amount);

        void unloadCargo(double amount);

        virtual ~Container();

};
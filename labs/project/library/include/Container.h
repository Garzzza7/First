class Container{

    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;

    public:

        Container();
        Container(int number);

        getNumber();

        getTare();

        setTare(double tareWeight);

        getMaxWeight();

        setMaxWeight(double maxWeight);

        getStrength();

        setStrength(double strength);

        getGrossWeight();

        getNetWeight();

        getMaxWeight();

        loadCargo(double amount);

        unloadCargo(double amount);

};
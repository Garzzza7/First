class Container{

    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;

    public:

        Container();
        Container(int number);

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

};
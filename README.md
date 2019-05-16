
# INF05010 - Combinatorial Optimization

This repository contains supplementary data used in INF05010 course for the 2019/1. A presentation of problems and their mathematical formulation can be found [here](problems-presentation.pdf) (in portuguese). A more complete specification of the project is available [here](project-specs.pdf) (in portuguese). Further information can be found in [Moodle platform](https://moodle.inf.ufrgs.br/course/view.php?id=255).

## Optimization project

### Instances for PFSP

Instance names are formatted as follows: for ``VFR60_10_3_Gap``, ``60`` refers to the number of tasks, ``5`` refers to the number of machines, ``3`` refers to instance id within ``60_10`` family.
The format of files is described in last paragraph of Section 3.1 of [Vallada et al. (2015)](https://www.sciencedirect.com/science/article/pii/S0377221714005992).

| Instance | \|_N_\| | \|_M_\| | BKS|
|----------|-------:|---------:|------:|
|[VFR10_15_1_Gap](instances/pfsp/VFR10_15_1_Gap.txt)      |10   |15  |1307   |
|[VFR20_10_3_Gap](instances/pfsp/VFR20_10_3_Gap.txt)      |20   |10  |1592   |
|[VFR20_20_1_Gap](instances/pfsp/VFR20_20_1_Gap.txt)      |20   |20  |2270   |
|[VFR60_5_10_Gap](instances/pfsp/VFR60_5_10_Gap.txt)      |60   | 5  |3663   |
|[VFR60_10_3_Gap](instances/pfsp/VFR60_10_3_Gap.txt)      |60   |10  |3423   |
|[VFR100_60_1_Gap](instances/pfsp/VFR100_60_1_Gap.txt)    |100  |60  |9395   |
|[VFR500_40_1_Gap](instances/pfsp/VFR500_40_1_Gap.txt)    |500  |40  |28548  |
|[VFR500_60_3_Gap](instances/pfsp/VFR500_60_3_Gap.txt)    |500  |60  |31125  |
|[VFR600_20_1_Gap](instances/pfsp/VFR600_20_1_Gap.txt)    |600  |20  |31433  |
|[VFR700_20_10_Gap](instances/pfsp/VFR700_20_10_Gap.txt)  |700  |20  |36417  |

__Note :__ Instances mirrored from [Web of Instances](http://www.webofinstances.com/index.php?option=com_fabrik&c=form&view=details&Itemid=62&fabrik=18&rowid=1&tableid=16&fabrik_cursor=0&lang=en).

__Note 2:__ Best known solutions are presented in supplementary material from [Vallada, Ruiz e Framinan (2015)](https://www.sciencedirect.com/science/article/pii/S0377221714005992).

__Note 3:__ A mathematical formulation of the problem can be found in [Tseng et al. (2004)](https://www.sciencedirect.com/science/article/pii/S030504830300152X).


### Instances for PMSP

Instance names are similar to PFSP: for ``20on4Rp50Rs50_1``, ``20`` refers to the number of tasks, ``4`` refers to the number of machines, ``1`` refers to instance id within ``20_4`` family. Other components of instance name describe parameters used on instance generation. Those information can be ignored.

| Instance | \|_N_\| | \|_M_\| | BKS|
|----------|-------:|---------:|------:|
|[20on4Rp50Rs50_1  ](instances/pmsp/20on4Rp50Rs50_1.dat) | 20  | 4   |  527.80   ± 15.43   |
|[60on8Rp50Rs50_1  ](instances/pmsp/60on8Rp50Rs50_1.dat) | 60  | 8   |  820.00   ± 9.62    |
|[60on4Rp50Rs50_1  ](instances/pmsp/60on4Rp50Rs50_1.dat) | 60  | 4   |  1673.20  ± 43.67  |
|[80on8Rp50Rs50_1  ](instances/pmsp/80on8Rp50Rs50_1.dat) | 80  | 8   |  1089.00  ± 7.25   |
|[80on12Rp50Rs50_1 ](instances/pmsp/80on12Rp50Rs50_1.dat) | 80  | 12  |   711.60  ± 5.73   |
|[100on2Rp50Rs50_1 ](instances/pmsp/100on2Rp50Rs50_1.dat) | 100 | 2   |  5872.00  ± 33.32  |
|[100on6Rp50Rs50_1 ](instances/pmsp/100on6Rp50Rs50_1.dat) | 100 | 6   |  1858.40  ± 9.07   |
|[100on8Rp50Rs50_1 ](instances/pmsp/100on8Rp50Rs50_1.dat) | 100 | 8   |  1371.00  ± 12.10  |
|[120on12Rp50Rs50_1](instances/pmsp/120on12Rp50Rs50_1.dat) | 120 | 12  |   1087.80 ± 32.26 |
|[120on10Rp50Rs50_1](instances/pmsp/120on10Rp50Rs50_1.dat) | 120 | 10  |   1326.80 ± 13.46 |

__Note :__ Instances mirrored from [Scheduling Research Virtual Center](https://sites.wp.odu.edu/schedulingresearch/paper).

__Note 2:__ Best known solutions are presented in [Ezugwu (2019)](https://www.sciencedirect.com/science/article/pii/S0950705119300504).

__Note 3:__ A mathematical formulation of the problem can be found in [Ezugwu (2019)](https://www.sciencedirect.com/science/article/pii/S0950705119300504).


### Instances for TSPDL

TSPDL instances are adaptations from classic datasets for TSP. Instance names use the following convention: for ``bayg29_10_1``, ``bayg`` indicates the dataset to which the instance belongs, and``29`` indicates the number of vertices. The other informations can be ignored.

| Instance | BKS (avg) |
|:---------|----------:|
|[bayg29_10_1    ](instances/tspdl/bayg29_10_1.dat)  |  1713.60     |
|[bayg29_50_1    ](instances/tspdl/bayg29_50_1.dat)  |  2091.00     |
|[gr17_25_1      ](instances/tspdl/gr17_25_1.dat)  |  2237.70       |
|[gr48_10_1      ](instances/tspdl/gr48_10_1.dat)  |  6635.70       |
|[gr48_25_1      ](instances/tspdl/gr48_25_1.dat)  |  5800.30       |
|[KroA200_50_1   ](instances/tspdl/KroA200_50_1.dat)  |  30665.20   |
|[KroA200_75_1   ](instances/tspdl/KroA200_75_1.dat)  |  30896.10   |
|[pcb442_50_1    ](instances/tspdl/pcb442_50_1.dat)  |  59858.30    |
|[pcb442_75_1    ](instances/tspdl/pcb442_75_1.dat)  |  61010.10    |
|[Ulysse_22_50_1 ](instances/tspdl/ulysses22_50_1.dat)  |  8425.60  |

__Note :__ Instances mirrored from [The TSPDL Lib](http://tspdl.jgr.no/).

__Note 2:__ Best known solutions are presented in [Todosijević et al. (2017)](https://link.springer.com/article/10.1007/s11590-014-0788-9).

__Note 3:__ A mathematical formulation of the problem can be found in [Rakke et al. (2012)](https://www.sciencedirect.com/science/article/pii/S0305048317300518).


# RMA

RMA is a solver to find an axis-parallel box containing the maximum net
weight of positivly minus negativly covered observations or vice versa
when each observation has a positive or negative weight.

## Software Requirement:
* [PEBBL](https://github.com/PEBBL/pebbl)
* C++ compiler
* MPI

## The description and user guide of RMA
* [Presentation](https://github.com/aik7/RMA/blob/master/RMA_slides.pdf)
* [User Guide](https://github.com/aik7/RMA/blob/master/RMA_user_guide.pdf)

## How to download and build RMA

* Clone or download this RMA repository
```
git clone https://github.com/aik7/RMA.git
```

* Run the following command for compiling and building applications
```
cd RMA
make
```

## Example commands to run RMA:

### Serial implementation
```
./rma <data_filename>
```

### Parallel implementation
```
mpirun -np 4 ./rma <data_filename>
```

### Example script
```
sh script/driver.sh
```

Please read the user guide about how to use parameters for the RMA solver.

## Reference

```
@phdthesis{AiThesis,
  author       = {Ai Kagawa},
  title        = {The Rectangular Maximum Agreement Problem: Applications and Parallel Solution},
  school       = {Rutgers University},
  year         = 2018
}
```

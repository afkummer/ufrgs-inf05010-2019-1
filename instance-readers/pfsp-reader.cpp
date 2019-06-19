#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

class PfspInstance {
public:
   PfspInstance(const char *fname);
   virtual ~PfspInstance();

   int getNumMachines() const;
   int getNumJobs() const;
   int getProcTime(int job, int machine) const;

   const char *getName() const;
   void writeFile(const char *fname) const;

protected:
   const std::string m_name;
   int m_numMachines, m_numJobs;
   std::vector <std::vector <int>> m_procTimes;
};

PfspInstance::PfspInstance(const char *fname): m_name(fname) {
   std::ifstream fid(fname);
   if (!fid) {
      std::cout << "Instance file could not be open to read.\n";
      std::abort();
   }

   fid >> m_numJobs >> m_numMachines;
   m_procTimes.resize(m_numMachines);
   for (auto &i: m_procTimes)
      i.resize(m_numJobs, std::numeric_limits<int>::max());

   for (int i = 0; i < m_numJobs; ++i) {
      for (int j = 0; j < m_numMachines; ++j) {
         int procId, proc;
         fid >> procId >> proc;
         m_procTimes[procId][i] = proc;
      }
   }
}

PfspInstance::~PfspInstance() {
   // Empty
}

int PfspInstance::getNumMachines() const {
   return m_numMachines;
}

int PfspInstance::getNumJobs() const {
   return m_numJobs;
}

int PfspInstance::getProcTime(int job, int machine) const {
   return m_procTimes[machine][job]; 
}

const char *PfspInstance::getName() const {
   return m_name.c_str();
}

void PfspInstance::writeFile(const char *fname) const {
   std::ofstream fid(fname);
   if (!fid) {
      std::cout << "Output file could not be open to write.\n";
      std::abort();
   }

   fid << getNumMachines() << ' ' << getNumJobs() << '\n';
   for (int i = 0; i < getNumMachines(); ++i) {
      for (int j = 0; j < getNumJobs(); ++j) {
         fid << j << ' ' << getProcTime(j, i) << ' ';
      }
      fid << "\n";
   }
}

int main(int argc, char **argv) {
   if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " <instance file>\n";
      return EXIT_FAILURE;
   }

   PfspInstance inst(argv[1]);

   return EXIT_SUCCESS;
}


#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

class PmspInstance {
public:
   PmspInstance(const char *fname);
   virtual ~PmspInstance();

   int getNumMachines() const;
   int getNumJobs() const;

   int getProcTime(int job, int machine) const;
   int getSetupTime(int predJob, int succJob, int machine) const;
   int getGijk(int predJob, int succJob, int machine) const;

   const char *getName() const;
   void writeFile(const char *fname) const;

protected:
   const std::string m_name;
   int m_num;
   int m_numMachines, m_numJobs;
   std::vector <std::vector <int>> m_procTimes; // [job][machine]
   std::vector <std::vector <std::vector <int>>> m_setupTimes; // [pred job][succ job][machine]
};

PmspInstance::PmspInstance(const char* fname): m_name(fname) {
   std::ifstream fid(fname);
   if (!fid) {
      std::cout << "Instance file could not be open to read.\n";
      std::abort();
   }

   fid >> m_num >> m_numMachines >> m_numJobs;

   m_procTimes.resize(m_numJobs);
   m_setupTimes.resize(m_numJobs);
   for (int i = 0; i < m_numJobs; ++i) {
      m_procTimes[i].resize(m_numMachines, std::numeric_limits<int>::max());
      m_setupTimes[i].resize(m_numJobs);
      for (int j = 0; j < m_numJobs; ++j) {
         m_setupTimes[i][j].resize(m_numMachines, std::numeric_limits<int>::max());
      }
   }

   for (int i = 0; i < m_numJobs; ++i) {
      for (int j = 0; j < m_numMachines; ++j) {
         fid >> m_procTimes[i][j];
      }
   }

   for (int k = 0; k < m_numMachines; ++k) {
      for (int i = 0; i < m_numJobs; ++i) {
         for (int j = 0; j < m_numJobs; ++j) {
            fid >> m_setupTimes[i][j][k];
         }
      }
   }

}

PmspInstance::~PmspInstance() {
   // Empty
}

int PmspInstance::getNumMachines() const {
   return m_numMachines;
}

int PmspInstance::getNumJobs() const {
   return m_numJobs;
}

int PmspInstance::getProcTime(int job, int machine) const {
   return m_procTimes[job][machine];
}

int PmspInstance::getSetupTime(int predJob, int succJob, int machine) const {
   return m_setupTimes[predJob][succJob][machine];
}

int PmspInstance::getGijk(int predJob, int succJob, int machine) const {
   return getProcTime(succJob, machine) + getSetupTime(predJob, succJob, machine);
}

const char *PmspInstance::getName() const {
   return m_name.c_str();
}

void PmspInstance::writeFile(const char* fname) const {
   std::ofstream fid(fname);
   if (!fid) {
      std::cout << "Output file could not be open to write.\n";
      std::abort();
   }

   fid << m_num << '\n' << m_numMachines << '\n' << m_numJobs << "\n\n";

   for (int i = 0; i < m_numJobs; ++i) {
      for (int j = 0; j < m_numMachines; ++j) {
         fid << m_procTimes[i][j] << ' ';
      }
      fid << '\n';
   }
   fid << "\n";

   for (int k = 0; k < m_numMachines; ++k) {
      for (int i = 0; i < m_numJobs; ++i) {
         for (int j = 0; j < m_numJobs; ++j) {
            fid << m_setupTimes[i][j][k] << ' ';
         }
         fid << "\n";
      }
      fid << "\n";
   }
}


int main(int argc, char **argv) {
   if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " <instance file>\n";
      return EXIT_FAILURE;
   }

   PmspInstance inst(argv[1]);
   inst.writeFile("/tmp/pmsp.txt");

   return EXIT_SUCCESS;
}


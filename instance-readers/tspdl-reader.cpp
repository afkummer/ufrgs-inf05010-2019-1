#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

class TspdlInstance {
public:
   TspdlInstance(const char *fname);
   virtual ~TspdlInstance();

   int getNumPorts() const;
   double getPortDemand(int port) const;
   double getPortDraftLimit(int port) const;

   const char *getName() const;
   void writeFile(const char *fname) const;

protected:
   const std::string m_name;
   std::vector <double> m_demands;
   std::vector <double> m_draftLims;

private:
   void readBaygFormat(std::ifstream &fid);
   void readKroaFormat(std::ifstream &fid);
};

TspdlInstance::TspdlInstance(const char* fname): m_name(fname) {
   std::ifstream fid(fname);
   if (!fid) {
      std::cout << "Instance file could not be open to read.\n";
      std::abort();
   }

   if (m_name.find("bayg") != std::string::npos ||
      m_name.find("gr") != std::string::npos ||
      m_name.find("ulysses") != std::string::npos) {
      readBaygFormat(fid);
   } else if (m_name.find("KroA") != std::string::npos ||
      m_name.find("pcb") != std::string::npos) {
      readKroaFormat(fid);
   } else {
      std::cout << "Unknown instance format for file '" << fname << "'.\n";
      std::abort();
   }
}

TspdlInstance::~TspdlInstance() {
   // Empty
}

const char *TspdlInstance::getName() const {
   return m_name.c_str();
}

void TspdlInstance::writeFile(const char* fname) const {
   std::ofstream fid(fname);
   if (!fid) {
      std::cout << "Output file could not be open to write.\n";
      std::abort();
   }
}

void TspdlInstance::readBaygFormat(std::ifstream& fid) {
}

void TspdlInstance::readKroaFormat(std::ifstream& fid) {
}



int main(int argc, char **argv) {
   if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " <instance file>\n";
      return EXIT_FAILURE;
   }

   TspdlInstance inst(argv[1]);
   inst.writeFile("/tmp/tspdl.txt");

   return EXIT_SUCCESS;
}


int test1(){
  auto f1 = new TFile("f1.root", "recreate");
  auto tree1 = new TTree("tree1","a test tree");

  float x;
  vector<float> Vx;
  tree1->Branch("x",&x,"x/F");
  tree1->Branch("vx",&Vx);

  const int NEVT=10;

  for(int i=0; i<NEVT; i++){
     x = i;
     int nVx = i+1;
     Vx.clear();

     for(int j=0; j<nVx; j++){
       Vx.push_back(i+0.1*j);
      }

     tree1->Fill();
  }

  f1->Write();
  f1->Close();

  return 0;
}

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int hours = 0;
        int totalEnergyRequired = 0;
        for(int x:energy)
                totalEnergyRequired+=x;
        if(totalEnergyRequired - initialEnergy > 0)
            hours += totalEnergyRequired - initialEnergy;
        
        if(totalEnergyRequired - initialEnergy >= 0)
            hours +=1;
        
        for(int i=0;i<experience.size();i++){
            if(experience[i] >  initialExperience){
                hours += experience[i] - initialExperience;
                initialExperience += experience[i] - initialExperience;
            }
            if(experience[i] == initialExperience){
                hours += 1;
                initialExperience += 1;
            }
            initialExperience += experience[i];
            
        }
        return hours;
    }
};

class Solution {
public:
    double euclideanDistance(double x1, double y1, double x2, double y2) {
        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    std::pair<double, double> weiszfeldAlgorithm(const vector<vector<int>>& positions, double epsilon = 4e-7, int maxIter = 1000) {
        double xCenter = 0.0, yCenter = 0.0;
        for (const auto& pos : positions) {
            xCenter += pos[0];
            yCenter += pos[1];
        }
        xCenter /= positions.size();
        yCenter /= positions.size();
        
        for (int iter = 0; iter < maxIter; ++iter) {
            double numeratorX = 0.0, numeratorY = 0.0, denominator = 0.0;
            bool allSamePoint = true;
            
            for (const auto& pos : positions) {
                double dist = euclideanDistance(xCenter, yCenter, pos[0], pos[1]);
                if (dist > epsilon) {
                    numeratorX += pos[0] / dist;
                    numeratorY += pos[1] / dist;
                    denominator += 1.0 / dist;
                    allSamePoint = false;
                } else {
                    numeratorX += pos[0];
                    numeratorY += pos[1];
                    denominator += 1.0;
                }
            }
            
            if (allSamePoint) return {xCenter, yCenter};
            
            if (std::abs(denominator) < epsilon) {
                // If denominator is too close to zero, return the current center
                return {xCenter, yCenter};
            }

            double newXCenter = numeratorX / denominator;
            double newYCenter = numeratorY / denominator;
            
            if (euclideanDistance(xCenter, yCenter, newXCenter, newYCenter) < epsilon) {
                return {newXCenter, newYCenter};
            }
            
            xCenter = newXCenter;
            yCenter = newYCenter;
        }
        
        return {xCenter, yCenter};
    }
    
    double getMinDistSum(vector<vector<int>>& positions) {
        if (positions.empty()) return 0.0;

        auto [xCenter, yCenter] = weiszfeldAlgorithm(positions);

        double sum = 0.0;
        for (const auto& pos : positions) {
            sum += euclideanDistance(xCenter, yCenter, pos[0], pos[1]);
        }
        return sum;
    }
};

import java.util.*;

// Class to represent each gate
class Input {
    char name;  // gate name
    String type;    // gate type 
    char c1;    // parent gate
    char c2;    // parent gate 2nd
    int[] signals;  // signals
    int[] outputSignals;    // out signals  

    Input(char name, String type, char c1, char c2, int T) { // no sig
        this.name= name;
        this.type= type;
        this.c1= c1;
        this.c2= c2;
        this.signals=new int[T];         
        this.outputSignals= new int[T]; //
    }
    Input(char name, int T) { // input
        this.name= name;
        this.type="INPUT";
        this.signals=new int[T];
        this.outputSignals=new int[T];
    }
    void setSignals(int[] signalValues) {   // setsignal
        this.signals=signalValues;
    }
}

public class B {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine().trim()); // gate no.
        Map<Character, Input> gateMap = new HashMap<>();

        // Reading gate definitions
        for (int i = 0; i < N; i++) {       // creating objects for the signals
            String line=sc.nextLine().trim();
            String[] parts= line.split("="); 
            char name=parts[0].trim().charAt(0);
            String rightSide=parts[1].trim();

            int firstParen=rightSide.indexOf('(');    // parent gates
            int lastParen=rightSide.indexOf(')');     // parent gates

            String gateType= rightSide.substring(0, firstParen).trim();    // type
            String connections= rightSide.substring(firstParen + 1, lastParen).trim();
            String[] prevGates=connections.split(",");

            char c1= prevGates[0].trim().charAt(0);
            char c2= prevGates[1].trim().charAt(0);

            // Create input gates
            gateMap.putIfAbsent(c1, null);
            gateMap.putIfAbsent(c2, null);

            // set T to 0 for creation, change later
            gateMap.put(name, new Input(name, gateType, c1, c2, 0));
        }

        int T = 0; // Number of cycles
        T = Integer.parseInt(sc.nextLine().trim());

        for (Map.Entry<Character, Input> entry : gateMap.entrySet()) {
            char gateName=entry.getKey();
            Input gate=entry.getValue();
            if (gate ==null) {
                gateMap.put(gateName,new Input(gateName,T)); // input gate
            } 
            else {
                gate.outputSignals=new int[T];    // output gate
            }
        }

        // Collect all input gates
        Map<Character, Input> inputGates = new HashMap<>();
        for (Input gate : gateMap.values()) {
            if (gate.type.equals("INPUT")) {
                inputGates.put(gate.name, gate);
            }
        }

        // Reading input signals for each input gate
        for (int i = 0; i < inputGates.size(); i++) {
            String signalLine = sc.nextLine().trim();

            String[] signalParts =signalLine.split("\\s+");

            char inputGateName=signalParts[0].charAt(0);
            Input gate = inputGates.get(inputGateName);

            int[] signals=new int[T];
            for (int j=1;j<= T; j++) {
                signals[j-1] =Integer.parseInt(signalParts[j]);
                if (signals[j-1]!=0 && signals[j-1]!= 1) {
                    signals[j-1]= 0;
                }
            }
            gate.setSignals(signals);
        }

        // Topological Sort to determine the order of gate evaluation
        List<Input> sortedGates = topologicalSort(gateMap);
        //List<Input> sortedGates = new ArrayList<>(gateMap.values());
        // Compute outputs for each gate in topological order
        for (Input gate : sortedGates) {
            if (gate.type.equals("INPUT")) {
                // For input gates, outputSignals are same as signals
                System.arraycopy(gate.signals, 0, gate.outputSignals, 0, T);
            }
            else {
                // For non-input gates, compute the output signals based on input gates
                Input input1 = gateMap.get(gate.c1);
                Input input2 = gateMap.get(gate.c2);
                gate.outputSignals = gateOutput(gate.type, input1, input2, T);
            }
        }

        char ansGate =sc.nextLine().trim().charAt(0); // last input
        Input gateToOutput=gateMap.get(ansGate);
        System.out.print("Gate " + gateToOutput.name + " signals: ");
        for (int cycle = 0; cycle < T; cycle++) {
            System.out.print("Cycle " + (cycle + 1) + ": " + gateToOutput.outputSignals[cycle] + "  ");
        }
    }

    // Method to perform Topological Sort using Kahn's Algorithm
    public static List<Input> topologicalSort(Map<Character, Input> gateMap) {
        Map<Character, Integer> inDegree = new HashMap<>();
        Map<Character, List<Character>> adjList = new HashMap<>();

        for (Map.Entry<Character, Input> entry : gateMap.entrySet()) {
            char gate = entry.getKey();
            Input gateObj = entry.getValue();
            inDegree.put(gate, 0);
            adjList.put(gate, new ArrayList<>());
        }

        // Build the graph
        for (Map.Entry<Character, Input> entry : gateMap.entrySet()) {
            char gate = entry.getKey();
            Input gateObj = entry.getValue();
            if (!gateObj.type.equals("INPUT")) {
                char input1 = gateObj.c1;
                char input2 = gateObj.c2;
                adjList.get(input1).add(gate);
                adjList.get(input2).add(gate);
                inDegree.put(gate, inDegree.get(gate) + 2);
            }
        }

        // Stack for gates with in-degree 0
        Stack<Character> stack = new Stack<>();
        for (Map.Entry<Character, Integer> entry : inDegree.entrySet()) {
            if (entry.getValue() == 0) {
                stack.push(entry.getKey());
            }
        }

        List<Input> sortedList = new ArrayList<>();
        while (!stack.isEmpty()) {
            char gate = stack.pop();
            sortedList.add(gateMap.get(gate));

            for (char neighbor : adjList.get(gate)) {
                inDegree.put(neighbor, inDegree.get(neighbor) - 1);
                if (inDegree.get(neighbor) == 0) {
                    stack.push(neighbor);
                }
            }
        }

        // Check if topological sort is possible
        if (sortedList.size() != gateMap.size()) {
            return null; // Cycle detected
        }

        return sortedList;
    }


    public static int[] gateOutput(String type, Input input1, Input input2, int T) {
        int[] outputSignals = new int[T];
        outputSignals[0]= 0;
        for (int cycle = 0; cycle < T-1; cycle++) {
            int val1 = input1.outputSignals[cycle];
            int val2 = input2.outputSignals[cycle];
            switch (type.toUpperCase()) {
                case "AND":
                    outputSignals[cycle+1] = val1 & val2;
                    break;
                case "OR":
                    outputSignals[cycle+1] = val1 | val2;
                    break;
                case "XOR":
                    outputSignals[cycle+1] = val1 ^ val2;
                    break;
                case "NAND":
                    outputSignals[cycle+1] = ~(val1 & val2) & 1;
                    break;
                case "NOR":
                    outputSignals[cycle+1] = ~(val1 | val2) & 1;
                    break;
                default:
                    break;
            }
        }
        return outputSignals;
    }
}
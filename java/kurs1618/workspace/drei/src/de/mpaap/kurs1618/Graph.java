package de.mpaap.kurs1618;

public class Graph {
    protected boolean[][] adjacencyMatrix; 
    protected String[] nodes;
    protected int indexOf(String node) throws GraphException {
        for (int i = 0; i < nodes.length; i++) {
            if (node.equals(nodes[i])) {
                return i; 
                } 
            } 
        throw new GraphException(); 
    } 
    
    public Graph (int nodeNumber) {
        nodes = new String[nodeNumber]; 
        adjacencyMatrix = new boolean[nodeNumber][nodeNumber]; 
    }
       
    public Graph(String[] nodes) {
        this(nodes.length); 
        for (int i = 0; i < nodes.length; i++) {
            this.nodes[i] = nodes[i];
        }
    }

    public String getNode(int index) throws GraphException {
    // . . . liefert den Namen des Knotens an der 
    // durch den Wert des Parameters bezeichneten Position, 
    // wenn diese einen Knoten bezeichnet; sonst eine GraphEacception.
        if(index >= 0 & index < nodes.length)
            return nodes[index];
        else
            throw new GraphException();
    }
    public int getNumbersOfNodes() {
        return nodes.length;
    }
    public void setNodes(String[] nodes) {
        // . . . weist den ersten k Elementen des Attributs nodes die 
        // entsprechenden Werte des Parameters nodes zu. k ist dabei das 
        // Minimum aus der Laenge des Attributs und des Parameters.
        int k = this.nodes.length <= nodes.length ? this.nodes.length : nodes.length;
        
        for(int i = 0; i < k; i++) {
            this.nodes[k] = nodes[k];
        }
    }
    public boolean isAdjacent(int index1, int index2) throws GraphException {
        // . . . liefert "wahr", wenn die Knoten mit Index 
        // indea 1 und indea:2 benachbart sind, sonst "falsch".

        /*
         * Moeglich, exception durch andere Methode wie folgt zu evozieren?
         */
        getNode(index1);
        getNode(index2);
        
        return adjacencyMatrix[index1][index2] && this.adjacencyMatrix[index2][index1];
    }
    public boolean isAdjacent(String node1, String node2) throws GraphException {
        // . . . liefert "wahr", wenn die Laender mit Mamen 
        // node 1 und mode2 benachbart sind, sonst "falsch".
        
        if(node1.equals(node2))
            return false;

        int indexNode1 = indexOf(node1);
        int indexNode2 = indexOf(node2);       
        
        //Fuer gewohenlich ueberprueft == ob beide Operanden auf das selbe Objekt referenzieren
        //und nicht auf semantische Gleichheit, daher sollte fuer den letzten Fall .equals() benutzt werden.
        //Fuer primitve Datentypen sollte == jedoch die selbe Funktion haben wie equals()? Oder liege 
        //ich hier falsch? 
        return adjacencyMatrix[indexNode1][indexNode2] == adjacencyMatrix[indexNode2][indexNode1];
    }
    public void addEdge(int index1, int index2) throws GraphException {
        // . . . fuegt Kante zwischen den Knoten mit 
        // Index indeac 1 und indea:2 ein, wenn diese 
        // Indizes von Laendern sind; sonst eine GraphEacception.
        
        /*
         * Moeglich, exception durch andere Methode wie folgt zu evozieren?
         */
        getNode(index1);
        getNode(index2);
        adjacencyMatrix[index1][index2] = adjacencyMatrix[index2][index2] = true;
    }
    public void addEdge(String node1, String node2) throws GraphException {
        // . . . fuegt Kante zwischen den Knoten mit 
        // Laendernamen node 1 und mode2 ein, wenn diese 
        // Knoten des Graphen bezeichnen, sonst eine GraphEacception.
        int index1 = indexOf(node1);
        int index2 = indexOf(node2);        
        adjacencyMatrix[index1][index2] = adjacencyMatrix[index2][index2] = true;
    }
}

class GraphException extends Exception {
    public GraphException() {
    }
    public GraphException(String msg) {
        super(msg);
    }
}

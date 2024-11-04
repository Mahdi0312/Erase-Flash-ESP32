#include <Arduino.h>
#include "esp_partition.h"

// Function to erase the entire flash memory
void eraseFlash() {
  // Get the partition information
  const esp_partition_t* partition = esp_partition_find_first(
      ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, NULL);
  
  if (partition != NULL) {
    Serial.println("Erasing Flash Memory...");
    
    // Erase the entire flash memory
    esp_err_t result = esp_partition_erase_range(partition, 0, partition->size);
    
    if (result == ESP_OK) {
      Serial.println("Flash Memory Erased Successfully.");
    } else {
      Serial.println("Failed to Erase Flash Memory.");
    }
  } else {
    Serial.println("No partition found!");
  }
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Give some time to open the Serial Monitor
  delay(2000);
  
  // Call the eraseFlash function
  eraseFlash();
}

void loop() {
  // Do nothing in the loop
}

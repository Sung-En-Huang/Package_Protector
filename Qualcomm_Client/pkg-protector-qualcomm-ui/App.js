import { StatusBar } from "expo-status-bar";
import { StyleSheet, Text, View } from "react-native";
import { Camera } from "expo-camera";
import { React, useEffect } from "react";
import CameraScreen from "./Cam";

export default function App() {
  useEffect(() => {
    (async () => {
      const { status } = await Camera.requestCameraPermissionsAsync();
      if (status === "granted") {
        // Permission granted
      } else {
        // Permission denied
      }
    })();
  }, []);

  return (
    <View style={styles.container}>
      <CameraScreen />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    flexDirection: "column",
    alignItems: "center",
    justifyContent: "center",
    maxHeight: "100%",
  },
});

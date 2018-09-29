import {DeviceEventEmitter, NativeModules} from 'react-native';

const _module = NativeModules.RNAlmoHisvoice;

export default {

    startRecognize() {
        _module.startRecognize();
    },

    stopRecognize() {
        return new Promise((resolve, reject) => {
            try {
                _module.stopRecognize();
            } catch (e) {
                reject(e);
                return;
            }
            DeviceEventEmitter.once('onAsrResults', resp => {
                resolve(resp);
            });
        });
    },

    subscribeOnAsrBeginOfSpeech(listener, context) {
        DeviceEventEmitter.addListener('onAsrBeginOfSpeech', listener, context);
    },

    unSubscribeOnAsrBeginOfSpeech() {
        DeviceEventEmitter.removeAllListeners('onAsrBeginOfSpeech');
    },

    subscribeOnAsrEndOfSpeech(listener, context) {
        DeviceEventEmitter.addListener('onAsrEndOfSpeech', listener, context);
    },

    unSubscribeOnAsrEndOfSpeech() {
        DeviceEventEmitter.removeAllListeners('onAsrEndOfSpeech');
    },

    subscribeOnRecorderVolumeChanged(listener, context) {
        DeviceEventEmitter.addListener('onRecorderVolumeChanged', listener, context);
    },

    unSubscribeOnRecorderVolumeChanged() {
        DeviceEventEmitter.removeAllListeners('onRecorderVolumeChanged');
    },

    subscribeOnAsrError(listener, context) {
        DeviceEventEmitter.addListener('onAsrError', listener, context);
    },

    unSubscribeOnAsrError() {
        DeviceEventEmitter.removeAllListeners('onAsrError');
    }

}
